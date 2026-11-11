#include<bits/stdc++.h>
using namespace std;
typedef long long llo;
const int N=2e5+5;
int l,r,n;
char c[N];
llo a[N],ll,rr,m,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		m+=a[i];
	}
	l=0,r=n+1,ll=0,rr=m+1;
	while(l<r){
		if(ll-0<=m+1-rr){
			l++;
			if(c[l]!=c[r])
				ans+=(min(m+1-rr,ll+a[l])-ll);
			ll+=a[l];
		}else{
			r--;
			if(c[l]!=c[r])
				ans+=(min(m+1-rr+a[r],ll)-(m+1-rr));
			rr-=a[r];
		}
	}
	cout<<ans;
	return 0;
}

