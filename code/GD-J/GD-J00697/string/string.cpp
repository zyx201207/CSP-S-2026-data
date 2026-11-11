#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<int,char>
#define fir first
#define sec second
int n,sp,ep;
PII a[2000008];
ll ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].fir>>a[i].sec;
	}
	sp=1,ep=n;
	while(sp<ep){
		if(a[sp].sec==a[ep].sec){
			int k=min(a[sp].fir,a[ep].fir);
			a[sp].fir-=k;
			a[ep].fir-=k;
			if(a[sp].fir==0) sp++;
			if(a[ep].fir==0) ep--;
		}
		else{
//			cout<<2<<' ';
			if(a[sp].fir==a[ep].fir){
				ans+=a[sp].fir;
				a[sp].fir=0;
				a[ep].fir=0;
				sp++;
				ep--;
			}
			else{
				int k=min(a[sp].fir,a[ep].fir);
				a[sp].fir-=k;
				a[ep].fir-=k;
				ans+=k;
				if(a[sp].fir==0) sp++;
				if(a[ep].fir==0) ep--;
			}
		}
//		cout<<sp<<' '<<ep<<' '<<ans<<'\n';
	}
	cout<<ans;
	return 0;
}
