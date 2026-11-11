#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m;
int a[N],b[N],c[N];
deque<int>q;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof b);
		int l=1;
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0)b[a[j]]=j,q.push_back(a[j]);
			else {
			//	cout<<a[j]<<" ";
				b[a[j]]=j;
				while(!q.empty()&&q.back()!=a[j]){
					b[q.back()]=0;
					q.pop_back();
				}
			}
		}
		while(!q.empty()){
			c[q.back()]++;
			q.pop_back();
		}	
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
	return 0;
} 
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
