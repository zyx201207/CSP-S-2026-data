#include<bits/stdc++.h>
using namespace std;
int const N=2e5+10;
long long a[N],p[N];
string s;
long long ans=0,cnt=1;
long long n,m;
void dfs(int step,int has){
	if(has==m||step==n+1){
		if(has<m||has>m)return;
		else{
			long long sum=p[1];
		
			for(int i=2;i<cnt;i++){
			
				
				sum=sum&p[i];
			}
			
			ans=max(ans,sum);
			
		}return;
	}int x=cnt;
	p[cnt]=a[step];
	cnt++;
	dfs(step+1,has+1);
	cnt=x;
	
	dfs(step+1,has);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}

	
	dfs(1,0);
	cout<<ans;

	return 0;
} 
