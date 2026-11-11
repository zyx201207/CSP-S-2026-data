#include<bits/stdc++.h>
using namespace std;
int a[500005],b[300005];
stack<int> pd;
stack<int> ls;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=1+i;j<=n;j++){
			if(pd.empty()){
				pd.push(a[j]);
				continue;
			}
			while(!pd.empty()){
				if(pd.top()==a[j]){
					while(!pd.empty())pd.pop();
					ls.push(a[j]);
					goto g;
				}
				ls.push(pd.top());
				pd.pop();
			}
			g:;
			while(!ls.empty()){
				pd.push(ls.top());
				ls.pop();
			}
		}
		while(!pd.empty()){
			b[pd.top()]++;
			pd.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<b[m]<<' ';
	return 0;
}
