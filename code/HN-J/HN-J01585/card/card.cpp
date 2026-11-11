#include<bits/stdc++.h>
using namespace std;
int n , m ;
int a[500005] ;
int sum[300005] ;
queue<int>q;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(q.empty()){
				q.push(a[j]);
			}else{
				bool flag=0;
				int nn=q.size();
				for(int k=1;k<=nn;k++){
					if(flag==1){
						q.pop();
					}else if(q.front()==a[j]){
						q.pop();
						flag=1;
					}else{
						q.push(q.front());
						q.pop();
					}
				}
				q.push(a[j]);
			}
		}
		while(!q.empty()){
			sum[q.front()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
} 
