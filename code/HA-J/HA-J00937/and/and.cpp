#include<bits/stdc++.h>
using namespace std;
int n1,m,a[200005][35],a2[35],ans;
void dfs(int n,int x[],int cnt){
	if(n==0){
		return ;
	}
	int x1[200005]={},cnt1=0;
	for(int i=1;i<=cnt;i++){
		if(a[x[i]][n]==1){
			x1[++cnt1]=x[i];
		}
	}
	cout<<cnt1;
	if(cnt1>=m){
		a2[n]=1;
		dfs(n-1,x1,cnt1);
	}else{
		dfs(n-1,x,cnt);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n1>>m;
	for(int i=1;i<=n1;i++){
		int x,cnt=0;
		cin>>x;
		while(x!=0){
			a[i][++cnt]=x%2;
			x/=2;
		}
	}	
	int x1[200005],x2[200005];
	for(int i=1;i<=200005;i++){
		x1[i]=i;
	}
	int cnt=n1;
	for(int i=30;i>=1;i--){
		int cnt1=0;
		for(int j=1;j<=cnt;j++){
			if(a[x1[j]][i]==1){
				x2[++cnt1]=x1[j];
			}
		}
		if(cnt1>=m){
			a2[i]=1;
			for(int j=1;j<=cnt1;j++){
				x1[j]=x2[j];
			}
			cnt=cnt1;
		}
	}
	for(int i=1;i<=30;i++){
		ans+=a2[i]*pow(2,i-1);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
