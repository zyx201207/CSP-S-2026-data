#include<bits/stdc++.h>
using namespace std;
int ans,m,n,al;
bool b[33][200005][2];
int mx[200005];
void dfs(int s,int k){
	if(k==0){
		int f=1;
		al=0;
		for(int i=1;i<=30;i++){
			if(b[i][s-1][0]==1){
				al+=f;
			}
			f*=2;
		}
		if(al>ans){
			ans=al;
		}
		return;
	}
	for(int i=s;i<=n-m+1;i++){
		for(int j=1;j<=30;j++){
			if(b[j][i][0]==0||b[j][s-1][0]==0){
				b[j][i][0]=0;
			}
		}
		dfs(i+1,k-1);
		for(int j=1;j<=30;j++){
			b[j][i][0]=b[j][i][1];
		}
	}
}
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	int x,t=0;
	cin>>n>>m;
	for(int i=1;i<=30;i++){
		b[i][0][0]=1;
		b[i][0][1]=1;
	}
	for(int i=1;i<=n;i++){
		cin>>x;
		int j=0;
		while(x>0){
			j++;
			if(x%2==1){
				b[j][i][0]=1;
				b[j][i][1]=1;
				if(j>t){
					t=j;
				}
			}
			mx[i]=j;
			x/=2;
		}
	}
	dfs(1,m);
	cout<<ans;
	return 0;
} 
