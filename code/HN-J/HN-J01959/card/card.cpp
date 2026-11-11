#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],d[500005];
int main(){
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int k[500005]={},s=0;stack<int> p;
		for(int j=i;j<=n;j++){
			if (k[a[j]]){
				while(p.top()!=a[j]){
					k[p.top()]=0;
					p.pop();
				}
			}
			else{
				k[a[j]]=1;
				p.push(a[j]);
			}
		}
		for(int j=1;j<=m;j++) d[j]+=k[j];
	}
	for(int i=1;i<=m;i++) cout<<d[i]<<" ";
	fclose(stdin);
    fclose(stdout);
	return 0;
}
