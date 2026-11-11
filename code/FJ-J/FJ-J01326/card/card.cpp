#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,c[500005],o,b[300005]={0},p;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&c[i]);
	for(i=1;i<=n;i++){
		stack<int> s;
		bool a[m]={0};
		int d[m];
		for(j=i;j<=n;j++){
			if(a[c[j]]){
				p=s.size();
				for(o=0;o<=p-d[c[j]];o++) s.pop();
			}else a[c[j]]=1;
			s.push(c[j]);
			d[c[j]]=s.size();
		}
		for(j=1;j<=m;j++){
			if(a[j]) b[j]++;
		}
	}
	for(i=1;i<=m;i++) printf("%d ",b[i]);
	return 0;
}