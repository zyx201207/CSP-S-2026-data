#include<iostream>
using namespace std;
int n,m,a[1000009];
bool b[1000009];
int heee,c[1000009],ans[1000009];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		for(int j=1;j<=m;j++){
			b[j]=false;
		}
		heee=k-1;
		for(int i=k;i<=n;i++){
			if(b[a[i]]==false){
				b[a[i]]=true;
				c[a[i]]=k;
			}
			else{
				heee=i-1;
				c[a[i]]=k;
			}
		} 
		for(int i=heee+1;i<=n;i++){
			ans[a[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
