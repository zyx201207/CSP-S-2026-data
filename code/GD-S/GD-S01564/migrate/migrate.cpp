#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std;
int C,T,n,d;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar(); }
	return x*f;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	C=read(),T=read();
	while(T--){
		n=read(),d=read();
		vector<int>a(n+5);
		int ans=0;
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				int cnt=0;
				for(int k=i+1;k<=j;k++){
					if(a[k]-a[i]==d&&a[j]-a[k]==d){
						cnt=0;
						break;
					}
					if(a[k]-a[i]<=d)cnt++;
				}
				if(cnt==2)ans++;
			}
		}
		cout<<ans<<"\n"; 
	} 
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/
