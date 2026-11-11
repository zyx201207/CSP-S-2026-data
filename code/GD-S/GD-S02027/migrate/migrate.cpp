#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int x[N];
int s[N];
int mark[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			s[i]=s[i]+x[i+1]-x[i];
		}
		int cnt=0;
		memset(mark,0,sizeof mark);
		for(int j=1;j<=n;j++){
			int sum=0;
			int maxn=0;
			int last=n;
			int f=0;
			for(int i=j;i<n-1;i++){
				if(s[i+2]-s[i]<=d){
				 	sum++;
				 	maxn=i+2;
				}
				if(sum==2){
					f=maxn;
				}
				if(sum>2){
					last=i+1;
					break;
				}
			}
			if(maxn==0){
				continue;
			}
			for(int i=maxn;i<=last;i++){
				if(mark[i]==0){
					mark[i]=1;
					cnt++;
				}
			}
		} 
		cout<<cnt<<"\n";
	}
	return 0;
}
