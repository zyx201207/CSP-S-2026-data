#include<bits/stdc++.h>
using namespace std;
long long n,m,x,arr[300010],sum[300010],num[300010],f[300010],ff[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		num[arr[i]]++;
	}
	for(int i=1;i<=n;i++){
		memset(f,0,sizeof(f));
		memset(ff,0,sizeof(ff));
		stack<long long>q;
		for(int j=i;j<=n;j++){
			if(f[arr[j]]==0){
				q.push(arr[j]);
				f[arr[j]]=1;
			}
			else{
				while(q.top()!=arr[j]){
					f[q.top()]=0;
					q.pop();
				}
				f[arr[j]]=1;
			}
		}
		for(int j=1;j<=n;j++){
			if(f[arr[j]]==1){
				if(ff[arr[j]]==0){
					sum[arr[j]]++;
					ff[arr[j]]=1;
				}
			}
		}	
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}

