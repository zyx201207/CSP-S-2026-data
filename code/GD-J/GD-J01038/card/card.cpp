#include<bits/stdc++.h>
using namespace std;
int a[500010],n,m,su[500010],k=1,sum[500010];
queue<int>q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int t=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(t--){
		for(int i=k;i<=n;i++){
			if(sum[a[i]]==0){
				q.push(a[i]);
				sum[a[i]]++;
			}
			else if(sum[a[i]]!=0){
				while(!q.empty()){
					sum[q.front()]=0;
					q.pop();
					
				}q.push(a[i]);
				sum[a[i]]++;
			}
		}for(int i=1;i<=m;i++){
			su[i]+=sum[i];
			sum[i]=0;
		
		}while(!q.empty())q.pop();
		k++;
		
	}for(int i=1;i<=m;i++){
		cout<<su[i]<<' ';
	}
	return 0;
} 
