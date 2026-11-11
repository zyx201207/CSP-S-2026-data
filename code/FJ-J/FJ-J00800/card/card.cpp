#include<bits/stdc++.h>
using namespace std;
int a[500005];
int xl[500005];
int ans[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	bool txa=true;
	for(int i=0;i<n;++i){
		scanf("%d",a+i);
		if(i!=0&&a[i]<a[i-1])
		txa=false;
	}
	if(m==1){
		printf("%d",n);
		return 0;
	}
	if(txa){
		int tz[300003];
		for(int i=0;i<n;++i){
			tz[a[i]]=i;
		}
		for(int i=1;i<=m;++i)
		printf("%d ",tz[i]+1);
		putchar(10);
		return 0;
	}
	for(int i=0;i<n;++i){
		int s=0,temp;
		for(int j=i;j<n;++j){
			++s;
			temp=s;
			for(int k=s-1;k>=0;--k){
				--temp;
				if(xl[k]==a[j]){
					s=temp;
					break;
				}
			}
			xl[s]=a[j];
		}
		for(int j=1;j<=m;++j){
			for(int k=0;k<=s;++k)
			if(j==xl[k]){
				++ans[j];
				break;
			}
		}
	}
	for(int i=1;i<=m;++i)
	printf("%d ",ans[i]);
	putchar(10);
}
