#include<bits/stdc++.h>
using namespace std;
int n,m,a[500009],book[500009],ans[500009];
stack<int> zhuo;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		memset(book,0,sizeof(book));
		for(int i=k;i<=n;i++){
			if(book[a[i]]==0){
				zhuo.push(a[i]);
				book[a[i]]=1;
			}
			else{
				int f=0;
				while(f!=a[i]){
					f=zhuo.top();
					zhuo.pop();
					if(f!=a[i]){
						book[f]=0;
					}
				}
				zhuo.push(a[i]);
				book[a[i]]=1;
			}
		}
		while(!zhuo.empty()){
			int f=zhuo.top();
			zhuo.pop();
			ans[f]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}