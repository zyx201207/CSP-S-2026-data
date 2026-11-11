#include<bits/stdc++.h>
using namespace std;
int sz=0;
int m,n;
int b[50000+10];
long long ans[30000+10];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}for(int i=1;i<=n;i++){
		bool v[30000+10]={};
		int a[50000+10]={};
		sz=0;
		for(int j=i;j<=n;j++){
			if(!v[b[j]]){
				v[b[j]]=1;
				a[++sz]=b[j];
			}
			else{
				while(a[sz]!=b[j]){
					v[a[sz]]=0;
					sz--;
				}a[sz]=b[j];
			}
		}for(int j=1;j<=sz;j++){
			ans[a[j]]++;
		}//cout<<ans[1];
	}for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
