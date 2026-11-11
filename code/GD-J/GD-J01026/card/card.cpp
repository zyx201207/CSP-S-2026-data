#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m;
int s[N];
int lst[N];
int ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)lst[j]=-1;
		for(int j=i;j<=n;j++){
			if(lst[s[j]]==-1){
				lst[s[j]]=j;
			}else{
				for(int k=lst[s[j]]+1;k<j;k++){
					lst[s[k]]=-1;
				}
				lst[s[j]]=j;
			}
		}
		for(int j=1;j<=m;j++){
			if(lst[j]==-1)continue;
			ans[j]++;
			lst[j]=-1;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
} 
