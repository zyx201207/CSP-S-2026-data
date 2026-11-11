#include<bits/stdc++.h>
using namespace std;
int n,a[5001],m,k[3001],p[3001],t[3001],f[3001];
stack<int>h;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		p[i]=t[a[i]];
		t[a[i]]=i;
	}
	puts("");
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(p[j]>=i) while(h.size()&&h.top()!=a[j]) h.pop();
			else h.push(a[j]);
		}
		for(int j=1;j<=m;j++) f[j]=0;
		while(h.size()) f[h.top()]++,h.pop();
		for(int j=1;j<=m;j++) if(f[j]) k[j]++;
	}
	for(int i=1;i<=m;i++) printf("%d ",k[i]);
}
