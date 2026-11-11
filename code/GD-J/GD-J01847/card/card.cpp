#include <bits/stdc++.h>
using namespace std;
int a[500005],b[500005];
bool f[500005];
stack <int> k;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(f[a[j]]==1){
				while(k.top()!=a[j]){
					f[k.top()]=0;
					k.pop();	
				}
			}
			else{
				k.push(a[j]);
				f[a[j]]=1;
			}
		}
		while(!k.empty()){
			b[k.top()]++;
			k.pop();
		}
		for(int j=1;j<=m;j++){
			f[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
