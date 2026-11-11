#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[50005],ans[30005];
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int q[50005];
		int book[30005]={0};
		int top=0;
		for(int j=i;j<=n;j++){
			if(book[a[j]]==1){
				while(q[top]!=a[j]&&top>0){
					book[q[top]]=0;
					top--;
				}
			}
			
			else{
				q[++top]=a[j];
				book[a[j]]=1;
			}
		}
		int bo[30005]={0};
		for(int j=1;j<=top;j++){
			if(bo[q[j]]==0){
				ans[q[j]]++;
				cout<<ans[q[j]];
				bo[q[j]]=1;
			} 
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[a[i]]<<' ';
	return 0;
}
