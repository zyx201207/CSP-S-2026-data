#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	char a[n+1];
	int ans[m+1];
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		int t[n+1]={};
		for(int j=i;j<=n;j++){
			for(int w=1;w<=j;w++){
			if(a[j]==t[w]){
				for(int o=w;o<j;o++)
					t[o]=0;
				}
				}
			
				t[j]=a[j];
		}
		for(int x=1;x<=m;x++){
			for(int y=1;y<=n;y++){
				if(t[y]==x)
				ans[x]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	cout<<ans[i]<<" ";
	
} 
