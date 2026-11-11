#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],f[300005],l[500005],k[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int T=n;
	while(T--){
		memset(l,0,sizeof(l));
		memset(k,0,sizeof(k));
		long long cnt=0;
		for(int i=n-T;i<=n;i++){
			if(k[a[i]]==0){
				l[++cnt]=a[i];
				k[a[i]]=cnt;
			} else{
//				cout<<cnt<<"--cnt"<<endl;
				for(int j=k[a[i]]+1;j<=cnt;j++){
					k[l[j]]=0;
					l[j]=0;
				}
				cnt=k[a[i]];
			}
//			for(int i=1;i<=3;i++) cout<<l[i]<<" ";
//			cout<<endl;
//			cout<<"kk";
//			for(int i=1;i<=3;i++) cout<<k[i]<<" ";
//			cout<<endl;
		}
//		cout<<"*****"<<endl;
		for(int i=1;i<=cnt;i++) f[l[i]]++;
	}
	for(int i=1;i<=m;i++) cout<<f[i]<<" ";
	return 0;
}

