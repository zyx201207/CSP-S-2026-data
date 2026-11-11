#include<bits/stdc++.h>
using namespace std;
int a[500001],a0[300005]={};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		bool s1s[300005]={};
		for(int j=i;j<=n;j++){
			//cout<<a[j]<<" ";
			if(s1s[a[j]]==1){
				cout<<"'";
				for(int k=1;k<=m;k++){
					s1s[k]=0;
				}
			}s1s[a[j]]=1;
			//cout<<s1s[a[j]]<<'\n';
		}for(int w=1;w<=m;w++){
			if(s1s[w]==1)a0[w]++;
		}
	}for(int i=1;i<=m;i++)cout<<a0[i]<<" ";
}
