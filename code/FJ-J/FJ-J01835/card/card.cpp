#include<bits/stdc++.h>
using namespace std;

int n,m,a[500005],c[500005];
bool b[500005];
deque<int>q;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++){
		for(int j=m;j<=n;j++){
			if(!b[a[j]])b[a[j]]=1;
			else{
				while(q.back()!=a[j])q.pop_back();
				q.push_back(a[j]);
			}
		}
		while(!q.empty()){
			c[q.front()]++;
			q.pop_front();
		}
	}
	for(int i=1;i<=m;i++)cout<<c[i];
}
