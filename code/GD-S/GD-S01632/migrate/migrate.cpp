#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,t,n,a[N],cnt,d,ans,sum;
bool b[N];
void dfs(int x,int y,int num){
	if(x>y)return ;
	if(x==y){
		if(!cnt){
		sum=num;cnt++;
		}
		else{
			if(sum!=num){
				sum=min(sum,num);
				if(num<sum)
				cnt=1;
				return ;
			}else cnt++;
		}
		return ;
	}
	if(b[x])return ;
	b[x]=1;
	for(int i=n;i>=x+1;i--){
		if(a[i]-a[x]<=d)dfs(i,y,num+1);
	}
	b[x]=0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in ","r",stdin);
	freopen("migrate.out ","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				memset(b,0,sizeof b);
				cnt=0;
				sum=2e9;
				dfs(j,i,0);
				ans+=(cnt==2);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
