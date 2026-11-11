#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[200005];
	int s[200005]={0}; 
	bool f[200005]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	stack<int> k;
	for(int t=1;t<=n;t++){
		for(int i=t;i<=n;i++){
			if(f[a[i]]==0){
				k.push(a[i]);
				f[a[i]]=1;
			}else{
				while(k.empty()==0&&k.top()!=a[i]){
					f[k.top()]=0;
					k.pop();
				}
			}
		}
		while(k.empty()==0){
			s[k.top()]++;
			f[k.top()]=0;
			k.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<' ';
	} 
	return 0;
}
