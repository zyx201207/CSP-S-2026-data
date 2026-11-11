#include<bits/stdc++.h>
using namespace std;
int a[200002];
bool xz[200002];
bool xzt[200002];
int n,m;
bool qw(int a,int i){
	return (a>>i)&1;
}
void sx(int w){
	int sum=0;
	for(int i=0;i<n;++i){
		xzt[i]=xz[i];
		if(xz[i]){
			if(qw(a[i],w)){
				++sum;
			}
			else
			xzt[i]=false;
		}
	}
	if(sum>=m){
		for(int i=0;i<n;++i)
		xz[i]=xzt[i];
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i)
	scanf("%d",a+i),xz[i]=true;
	for(int i=29;i>=0;--i)
	sx(i);
	int ans=2147483647;
	for(int i=0;i<n;++i){
		if(xz[i])
		ans&=a[i];
	}
	printf("%d\n",ans);
}
