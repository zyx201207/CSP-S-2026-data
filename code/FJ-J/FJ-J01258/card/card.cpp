#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,b[N],t[N],w[N],c[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int flag=1;
	for(int i=1;i<=n;i++){
		cin>>b[i],w[b[i]]=i;
		if(b[i]>b[i+1]&&i!=n) flag=0;
	}
	if(flag){
		for(int i=1;i<=n;i++){
			for(int j=i;j<n;j++){
				if(b[j]!=b[j+1]) t[b[j]]++;
			}
		}
		for(int i=1;i<=m;i++) cout<<b[i]<<" ";
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[j]!=b[n]&&!c[b[j]]) t[b[j]]++,c[b[j]]=1;
			else break;
		}
		for(int i=1;i<=n;i++) c[b[i]]=0;
	}
	t[b[n]]=n;
	for(int i=1;i<=m;i++) cout<<t[i]<<" ";
//4 3 1 2 1 3
	return 0;
}
