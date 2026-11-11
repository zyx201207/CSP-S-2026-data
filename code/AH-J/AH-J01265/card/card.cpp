#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
int a[N];
bool f[N];
int cnt[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=5005){
		for(int i=1;i<=n;i++){
			stack<int> q;
			for(int j=i;j<=n;j++){
				if(f[a[j]]==0){
					f[a[j]]=1;
					q.push(a[j]);
				}else{
					while(q.top()!=a[j]){
						f[q.top()]=0;
						q.pop();
					}
				}
				
			}
			while(!q.empty()){
 				cnt[q.top()]++;
				q.pop();
			}
			for(int j=1;j<=m;j++){
				f[j]=0;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<cnt[i]<<" ";
		}
	}else{
		for(int i=1;i<=n;i++){
			cnt[a[i]]++;
		}
		int sum=0;
		for(int i=1;i<=m;i++){
			sum+=cnt[i];
			cout<<sum<<" ";
		}
	}
	return 0;
}
