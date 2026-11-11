#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500005],b[300005],l[500005]={0};
int x(int k,int o){
	for(int h=1;h<o;h++)
	if(l[h]==k)return h+1;
	return 1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int v=x(a[j],j)-1;
			if(v){
				for(int h=v;h<j;h++)
				l[h]=0;
			}
			l[j]=a[j];
		}
		for(int j=i;j<=n;j++){
		    if(l[j])b[l[j]]++;
		    l[j]=0;
		}
	}
	for(int i=1;i<=m;i++)
	printf("%lld ",b[i]);
	fclose(stdin);fclose(stdout);
	return 0;
}
