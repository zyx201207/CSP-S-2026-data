#include<bits/stdc++.h>
using namespace std; 
const long long N=2e5+5;
long long n,m,x,y,z,op,sum,t,k,a[N],b[N],f[N],flag,js,ans,zdw,maxx;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i],maxx=max(maxx,a[i]);
	while(maxx){
		zdw++;
		maxx/=2;
	}
	for(int j=zdw;j>=1;j--){
		js=0;
		for(int i=1;i<=n;i++)
			if((((a[i]>>(j-1))%2)==1)&&(!f[i]))
				js++;
//		for(int i=1;i<=n;i++)
//			cout<<(a[i]>>(j-1))%2<<" ";
//		cout<<"\n";
		if(js>=m){
			ans+=(1<<(j-1));
			for(int i=1;i<=n;i++)
				if(((a[i]>>(j-1))%2)==0)
					f[i]=1;
		}
	}
	cout<<ans;
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
//	freopen("and2.in","r",stdin);
//	freopen("and2.out","w",stdout);
//	freopen("and3.in","r",stdin);
//	freopen("and3.out","w",stdout);
//	freopen("and4.in","r",stdin);
//	freopen("and4.out","w",stdout);
//	freopen("and5.in","r",stdin);
//	freopen("and5.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
/*
5 3
31 3 1 15 7
*/
