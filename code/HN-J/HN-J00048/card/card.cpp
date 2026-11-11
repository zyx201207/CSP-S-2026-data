#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],s[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		bool f[505]={};
		for(int j=i;j<=n;j++){
			if(f[a[j]]==1){
				for(int k=1;k<=m;k++){
					f[k]=0; 
				}
			}
			f[a[j]]=1;
		}
		for(int j=1;j<=m;j++){
			if(f[j]==1){
				s[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}

