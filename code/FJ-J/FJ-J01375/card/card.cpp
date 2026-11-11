#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
const int maxm=3e5+5;
int n,m;
int a[maxn];
stack <int> q;
int t[maxm];
long long ans[maxm];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=n;j++){
		for(int i=j;i<=n;i++){
			if(t[a[i]]==0){
				q.push(a[i]);
				t[a[i]]++;
			}else{
				while(q.top()!=a[i]){
					t[q.top()]--;
					q.pop();
				}
			}
		}
		while(!q.empty()){
			ans[q.top()]++;
			t[q.top()]--;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
