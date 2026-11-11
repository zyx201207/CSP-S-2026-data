#include <bits/stdc++.h>
using namespace std;
int n,m;
int pl[300010];
int s[300010];
int p(int x){
	int shu[m+10];
	int dc[m+10];
	for(int i=x;i<=n;i++){
		if(shu[pl[i]]==0){
			shu[pl[i]]=i;
			dc[i]=pl[i];
		}else for(int j=shu[pl[i]];j<=i-1;j++){
			dc[j]=0;
		}
	} 
	for(int i=x;i<=n;i++){
		if(dc[i]>0)s[dc[i]]++;
	}
	if(x<=n)p(x+1);
}
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>pl[i];
	p(1);
	for(int i=1;i<=m;i++)cout<<s[i];
	return 0;
}
