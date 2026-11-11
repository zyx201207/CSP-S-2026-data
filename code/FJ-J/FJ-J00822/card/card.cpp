#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
const int N=5e5+5;
const int M=3e5+5;
int n,m,a[N],ans[M];
bool book[M];
stack<int> S;//num,dfn
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(book[a[j]]){
				while(S.top()!=a[j]){
//					ans[S.top().F]+=(n-i+1)-S.top().S;
					book[S.top()]=0;
					S.pop();
				}
			}else{
				S.push(a[j]);
				book[a[j]]=1;
			}
		}
		while(S.size()){
			ans[S.top()]++;
			book[S.top()]=0;
			S.pop();
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
} 
