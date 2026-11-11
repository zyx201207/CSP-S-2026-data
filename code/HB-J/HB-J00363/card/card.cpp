#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200010],book[200010],f[200010];
stack<int>q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		for(int i=k;i<=n;i++){
			if(book[a[i]]==0){
				q.push(a[i]);
				book[a[i]]=1;
			}
			else{
				while(q.top()!=a[i]) book[q.top()]=0,q.pop();
				q.push(a[i]);
			}
		}
		//~ for(int i=1;i<=m;i++){
			//~ cout<<book[i]<<endl;
		//~ }
		for(int i=1;i<=m;i++){
			f[i]+=book[i];
		}
		memset(book,0,sizeof book);
	}
	for(int i=1;i<=m;i++){
		cout<<f[i]<<' ';
	}
	return 0;
}
