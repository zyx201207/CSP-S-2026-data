#include<bits/stdc++.h>
using namespace std;
int a[500009],ans[300009],book[300009];
stack<int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		cout<<n;
		return 0;
	}
	for(i=1;i<=n;i++){
		memset(book,0,sizeof(book));
		for(j=i;j<=n;j++){
			if(!book[a[j]]){
				s.push(a[j]);
				book[a[j]]++;
			}
			else{
				int t=s.top();
				while(t!=a[j]){
					book[t]--;
					s.pop();
					t=s.top();
				}
			}
		}
		while(!s.empty()){
			int k=s.top();
			ans[k]++;
			s.pop();
		}
	}
	for(i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}