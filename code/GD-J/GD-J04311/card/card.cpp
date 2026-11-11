#include<iostream>
#include<vector>
#include<set>
#include<stack>
#define int long long
using namespace std;
int n,m,a[500005],la[300005],maxx,ans[300005],instk[300005],top;
int stk[500005];
bool vis[500005];
//vector<int>v[500005];
//struct tmpint{
//	int loc;
//	bool operator<(tmpint b)const{
//		return loc>b.loc;
//	}
//}; 
//stack<int>s;
signed main(){
	freopen("card.in","r",stdin);freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i =1;i<=n;i++){
		cin>>a[i];
		la[a[i]] = i;
	}
	for(int i =1;i<=n;i++){
		for(int j =1;j<=m;j++)instk[j] = vis[j] = 0;
		for(int j =i;j<=n;j++){
			if(instk[a[j]]){
				while(top>1&&stk[top]!=a[j]){
					instk[stk[top]] = 0;
					--top;
				}
				--top;
			}
			stk[++top] = a[j];
			instk[a[j]] = 1;
		}
		while(top){
			vis[stk[top]] = 1;
//			cout<<stk[top]<<" ";
			--top;
		}
//		cout<<"\n";
		for(int j =1;j<=m;j++){
			ans[j] += instk[j]; 
		}
	}
	for(int i =1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
//	for(int i =n;i>=1;i--){
//		if(lla[a[i]]>0){
//			
//		}
//		lla[a[i]] = i;
//	}
}
/*
4 3 
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1

*/
