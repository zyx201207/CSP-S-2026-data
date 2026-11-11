#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,a[N],c[M],ans[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
//		cout<<i<<"\n";
		for(int j=1;j<=m;j++)c[j]=0;
		for(int j=i;j<=n;j++){
			if(c[a[j]]==1){
//				cout<<"Y "<<a[j]<<"\n";
				for(int k=j-1;k>=1;k--){
					if(a[k]==a[j])break;
					c[a[k]]=0;
				}
			}else{
//				cout<<"N "<<a[j]<<"\n";
				c[a[j]]=1;
			}
//			for(int i=1;i<=m;i++)cout<<c[i]<<" ";
//			cout<<"\n--------\n";
		} 
		for(int i=1;i<=m;i++){
			ans[i]+=c[i];
		}
//		for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
//		cout<<"\n========\n";
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

