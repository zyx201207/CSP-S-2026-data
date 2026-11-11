#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n,m;
int a[N];
bool f[N];
int ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		stack<int> q;
		memset(f,false,sizeof(f));
//		cout<<i<<"\n";
		for(int j=i;j<=n;j++){
//			cout<<j<<" "<<f[a[j]]<<"\n";
			if(!f[a[j]]){
				q.push(a[j]);
				ans[a[j]]++;
				f[a[j]]=true;
			}
			else{
//				cout<<"Yes"<<"\n";
//				cout<<q.top()<<"\n";
				while(q.top()!=a[j]){
//					cout<<"Yes"<<"\n";
					f[q.top()]=false;
					ans[q.top()]--;
					q.pop();
				}
			}
		}
//		
//	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
//	cout<<"\n";
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
