#include<bits/stdc++.h> 
using namespace std;
int n,m;
int arr[500010],a[500010],ans[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		a[i]=arr[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			bool b1=0;
			for(int k=i;k<j;k++){
				if(a[j]==a[k]){
					b1=1;
				}
				if(b1){
					a[k]=-1;
				}
			}
		}
//		for(int j=i;j<=n;j++){
//			cout<<a[j]<<" ";
//		}
//		cout<<"\n";
		for(int j=i;j<=n;j++){
			if(a[j]==-1) continue;
			ans[a[j]]++;
		}
		for(int j=i;j<n;j++){
			a[j]=arr[j];
		}
	}
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	return 0;
}
