#include<bits/stdc++.h>
using namespace std;
int a[2005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	queue<int> q;
	queue<int> id;
	int n,m;
	cin>>n>>m;
	q.push(0);
	id.push(0);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++){
		int gh=q.size();
		while(gh--){
			for(int j=id.front()+1;j<=n;j++){
				if(id.front()==0)
					q.push(a[j]);
				else
					q.push(q.front()&a[j]);
				id.push(j);
			}
			q.pop();
			id.pop();
		}
	}
	int ans=0;
	while(!q.empty()){
		ans=max(ans,q.front());
		q.pop();
	}
	cout<<ans;
	return 0;
} 

/*

4 2
3 15 12 12

*/


/*

5 3
31 3 1 15 7

*/
