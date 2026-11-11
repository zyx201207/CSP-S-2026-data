#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=1e5+5;
int a[N],ans[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		queue<int> qa,qb;
		for(int j=i;j<=n;j++){
			int k=a[j];
			while(!qa.empty()){
				if(qa.front()==k){
					while(!qa.empty())
						qa.pop();
					break;
				}
				qb.push(qa.front());
				qa.pop();
			}
			while(!qb.empty()){
				qa.push(qb.front());
				qb.pop();
			}
			qa.push(k);
		}
		while(!qa.empty()){
			ans[qa.front()]++;
			qa.pop();
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}
