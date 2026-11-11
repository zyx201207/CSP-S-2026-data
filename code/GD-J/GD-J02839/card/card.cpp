#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],d[500005];
bool b[300005];
stack<long long> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0){
				b[a[j]]=1,q.push(a[j]);
			}
			else{
				while(q.top()!=a[j])b[q.top()]=0,q.pop();
			}
		}
		while(q.size()){
			b[q.top()]=0,d[q.top()]++,q.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<d[i]<<" ";
	return 0;
} 
