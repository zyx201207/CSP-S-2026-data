#include<bits/stdc++.h>
using namespace std;
stack<int>a;
int n,m,b[500005],f[300005],s[500005],k[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			f[j]=0;k[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(k[b[j]]==1){
				while(a.top()!=b[j]){
					k[a.top()]=0;
					a.pop();
				}
			}
			k[b[j]]=1;
			a.push(b[j]);
		}
		while(a.size()>0){
			if(!f[a.top()]){
				f[a.top()]=1;
				s[a.top()]++;
			}
			a.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	
	return 0;
}
