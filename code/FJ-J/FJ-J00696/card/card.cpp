#include<bits/stdc++.h>
using namespace std;
stack<int>p1;
int a[999999],ans[999999];
bool t[999999];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(t,0,sizeof(t));
		for(int j=i;j<=n;j++){
			if(t[a[j]])
				while(!p1.empty())
					p1.pop();
			else t[a[j]]=1;
			p1.push(a[j]);
		}
		while(!p1.empty()){
			ans[p1.top()]++;
			p1.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}
