#include <bits/stdc++.h> 
using namespace std;
#define ll long long

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin>>N;
	vector<ll> a(N+1,0);
	vector<char> c(N+1,char(0));
	ll l=1,r=0;
	for(int i=1;i<=N;i++){
		cin>>a[i]>>c[i];
		r+=a[i];
	} 
	
	ll ql=1,qr=N;
	ll ans=0;
	while(r-l>1){
		if(a[ql]==a[qr] && c[ql]==c[qr]){
			l+=a[ql];
			r-=a[qr];
			ql++;
			qr--;
		}
		else if(a[ql]==a[qr]){
			l+=a[ql];
			r-=a[qr];
			ans+=a[ql];
			ql++;
			qr--;
		}
		else{
			if(a[ql]>a[qr]){
				if(c[ql]!=c[qr]) ans+=a[qr];
				l+=a[qr];
				r-=a[qr];
				a[ql]-=a[qr];
				qr--;
			}
			else{
				if(c[ql]!=c[qr]) ans+=a[ql];
				l+=a[ql];
				r-=a[ql];
				a[qr]-=a[ql];
				ql++;
			}
		}
	}
	
	cout<<ans;
	
	return 0;
}
