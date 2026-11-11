#include<bits/stdc++.h>
using namespace std;
int n,m,a[500002],ans[500002];
bool p[50003];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		memset(p,0,sizeof(p));
		for(int j=i;j<n;j++){
			if(p[a[j]]){
				for(int k=j-1;k>=0;k--){
					if(a[k]==a[j])break;
					//if(p[a[k]])ans[a[k]]--;
					p[a[k]]=0;
					
				}
			}else{
				p[a[j]]=1;
				//ans[j]++;
			}
		}for(int j=1;j<=m;j++){
			if(p[j])ans[j]++;
		}
	}for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
//1
//1 2
//1
