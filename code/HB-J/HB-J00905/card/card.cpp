#include<iostream>
#include<cstring>
using namespace std;
int a[500005];
int ans[300005];
int book[300005];
int main(){
	
	int n,m;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int head=i-1,top=0;
		memset(book,-1,sizeof(book));
		for(;head<n;head++){
			if(book[a[head]]==-1){
				book[a[head]]=top++;
			}
			else{
				for(int j=0;j<=m;j++){
					if(book[j]>book[a[head]]){
						book[j]=-1;
						top--;
					}
				}
				book[a[head]]=top++;
			}
		}
		for(int j=0;j<=m;j++){
			if(book[j]!=-1){
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
