#include<bits/stdc++.h>
using namespace std;
long long s[100005];
long long bo[100005];
int maxx=-1,ww=0;
int n1,m1,c=0;
void dfs(int m){
	int ww1;
	c++;
	for(int i=1;i<=n1;i++){
		if(c==1){
			ww=s[i];
			bo[i]=1;
			if(m-1>0){
				dfs(m-1);
				bo[i]=0;
			}
		}
		else if(bo[i]==0){
			ww1=ww;
			ww&=s[i];
		}
		else if(c==m1&&bo[i]==0){
			maxx=max(ww,maxx);
			ww=ww1;
		}
		
		
	}
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n1>>m1;
	for(int i=1;i<=n1;i++){
		cin>>s[i];
	}
	dfs(m1);
	cout<<maxx;
	return 0;
} 
