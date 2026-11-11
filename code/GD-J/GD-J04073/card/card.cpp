#include<bits/stdc++.h>
using namespace std;
const int N=1310720;
int a[N],cnt[N];
bool st[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		stack<int> zhuo;
		for(int j=i;j<=n;j++){
			if(st[a[j]]==0){
				st[a[j]]=1;	
			}
			else{
				while(st[a[j]]!=0 and zhuo.empty()==0){
					st[zhuo.top()]=0;
					zhuo.pop();
				}
				zhuo.push(a[j]);
				st[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++){
			if(st[a[j]]==1){
				cnt[a[j]]++;
				st[a[j]]=0;
			}
		}
		while(zhuo.empty()==0) zhuo.pop();
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
	return 0;
} 
