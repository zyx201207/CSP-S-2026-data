#include<bits/stdc++.h>
using namespace std;
int a[500005],sum[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	stack<int> s;
	int n,m;
	cin>>n>>m;
	bool f[300005];
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) f[j]=false;
		for(int j=i;j<=n;j++){
			if(f[a[j]]) while(s.top()!=a[j]) s.pop();
			else{
				f[a[j]]=true;
				s.push(a[j]);
			}
		}
		for(int j=1;j<=m;i++) if(f[j]) sum[j]++;
	}
	for(int i=1;i<=m;i++) cout<<sum[i]<<" ";
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
