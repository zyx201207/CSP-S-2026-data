#include<bits/stdc++.h>
using namespace std;
struct node{
	int zh,xl,ti;
}a[100005];
int b[10100];
int top=1,tail=1;
const int MAX_INT=214748364;
int c[100003];
bool flag=false;
int ghfj,n,m,d,p,op,ans,e;
int wt[100005];
void dfs(int s,int sum){
	if(s==e){
		ans=min(ans,sum);
		return ;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=c[i];j++){
			for(int t=1;t<=c[i];t++){
				if(a[j].zh==s && a[t].zh==e){
					flag=true;
				}
			}
		}
	}
	if(flag){
		sum=sum+a[e].ti+wt[e];
		dfs(e,sum);
	}else{
		
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>ghfj>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>wt[i];
	}
	for(int i=1;i<=n;i++){
		cin>>op;
		c[i]=op;
		while(op--){
			cin>>a[i].zh>>a[i].ti;
			a[i].xl=i;
		}
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			for(int t=1;t<=c[i];t++){
				for(int g=1;g<=c[j];g++){
					if(a[t].zh==a[g].zh){
						b[top]=a[t].zh;
					}
				}
			}
		}
	}
	while(p--){
		flag=false;
		ans=MAX_INT;
		int s;
		cin>>s>>e;
		dfs(s,0);
		cout<<ans<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
