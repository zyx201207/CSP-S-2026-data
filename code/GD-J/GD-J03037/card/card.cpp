#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans[300005];
bool b[300005]={0};
stack<long long> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(!q.empty()){
				q.pop();
			}
			b[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(b[a[j]]){
				while(1){
					int num=q.top();
					if(num==a[j]){
						q.pop();
						q.push(num);
						break;
					}
					else{
						q.pop();
						b[num]=0;
					}
				}
			}
			else{
				q.push(a[j]);
				b[a[j]]=1;
			}
		} 
		for(int j=1;j<=m;j++){
			if(b[j]){
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 

