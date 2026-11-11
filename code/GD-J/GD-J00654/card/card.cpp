#include<bits/stdc++.h>
using namespace std;
long long n,m,key=-1;
long long a[500010],ans[500050];
bool iff[500050],iff_u[500050],iff_num[300030];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	memset(ans,0,sizeof(ans));
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		key=max(key,a[i]);
		iff_num[a[i]]=true;
	}
	for(int i=1;i<=n;i++){
		stack<long long>q;
		for(int j=1;j<=n;j++){
			if(iff[a[j]]==false&&iff_u[j]==false){
				q.push(a[j]);
				iff[a[j]]=true;
			}else{
				if(iff_u[j]==true){
					continue;
				}
				if(iff[a[j]]==true){
					iff_u[j]=true;
					while(q.top()!=a[j]){
						q.pop();
					}
					q.push(a[j]);
				}
			}
		}
		while(!q.empty()){
			ans[q.top()]++;
			q.pop();
		}
		memset(iff,0,sizeof(iff));
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(iff_num[a[i]]==true){
			iff_num[a[i]]=false;
			cout<<ans[a[i]]<<" ";
			continue;
		}
	}
}
