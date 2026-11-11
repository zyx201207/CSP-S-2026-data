#include<bits/stdc++.h>
#define int long long
using namespace std;
int i,j,k;
int n,m;
bool fl[20005];
int a[200005],ans[20006];
int dp[200005],maxn=-1;

signed main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
cin>>n>>m;
	for(i=1;i<=n;i++){cin>>a[i];maxn=max(maxn,a[i]);}
	for(i=1;i<=n;i++){
		memset(fl,0,sizeof(fl));
		stack<int>s;
		for(j=i;j<=n;j++){
			if(fl[a[j]]==1){
				while(s.top()!=a[j]&&(!s.empty())){
					
					fl[s.top()]=0;
					s.pop();
				}
			}
			s.push(a[j]);//cout<<s.top()<<' ';
			fl[a[j]]=1;
				for(j=1;j<=maxn;j++){
			cout<<fl[j]<<" ";
		}
		cout<<endl;
			
		}
		for(j=1;j<=maxn;j++){
			if(fl[j]!=0) ans[j]++;
		}
	}
	for(i=1;i<=maxn;i++){if(ans[j]>0) cout<<ans[j]<<' ';}
	return 0;
}
