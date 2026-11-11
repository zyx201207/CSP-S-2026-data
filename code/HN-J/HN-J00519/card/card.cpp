#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],num,ans[500005],flag=1,one[300005],qzh=0;
stack<int>pq;
map<int,int>mo;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		one[a[i]]++;
		if(a[i]<a[i-1]){
			flag=0;
		}
	}
	
	if(flag==1){
		for(int i=1;i<=m;i++){
			qzh+=one[i];
			cout<<qzh<<" ";
		}
		return 0;
	}
	if(n<=5000){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(mo[a[j]]==0){
					num++;
					mo[a[j]]=num;
					pq.push(a[j]);
				}
				else{
					while(pq.top()!=a[j]){
						mo[pq.top()]=0;
						num--;
						pq.pop();
					}
				}
			}
			for(int i=1;i<=m;i++){
				if(mo[i]!=0){
					ans[i]++;
				}
			}
			while(!pq.empty()){
				pq.pop();
			}
			mo.clear();
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
		return 0;
	}
}
