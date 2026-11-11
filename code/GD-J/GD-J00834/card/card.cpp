#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=7e5+5;
int a[N],ton[N],ans[N];
stack<int> q;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		for(int j=1;j<=m;j++){
			ton[j]=0;
		}
		for(int i=k;i<=n;i++){
			if(ton[a[i]]!=0){
				while(q.top()!=a[i]){
					ton[q.top()]--;
					q.pop();
				}
				q.pop();
				ton[a[i]]--;
			}
			q.push(a[i]);
			ton[a[i]]++;
		}
		while(!q.empty()){
			ans[q.top()]++;
			q.pop();
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
