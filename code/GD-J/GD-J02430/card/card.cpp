#include<bits/stdc++.h>
using namespace std;
int a[100001]={0};
int b[100001]={0};
vector<int> c(1000000,0);
int n,m;
void de(int d){
	int u=-1;
	for(int i=0;i<c.size();i++){
		if(c[i]==d){
			u=i;
			break;
		}
	}
	if(u!=-1) for(int i=u;i<c.size();i++) c[i]=-1;
	c.push_back(d);
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int k=1;k<=n;k++){
		for(int i=k;i<=n;i++) de(a[i]);
		for(int i=0;i<c.size();i++){
			if(c[i]==-1) continue;
			b[c[i]]++;
			c[i]=-1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
} 
