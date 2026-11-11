#include <bits/stdc++.h>
using namespace std;
int n,a[201000],m;
map<string,int>b;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int ans=0;
	for(int tmp=30;tmp>=0;tmp--){
		int dec=(1<<tmp),sum=0;
		for(int i=1;i<=n;i++)if(a[i]>=dec)sum++;
		if(sum>=m){
			int top=0;
			for(int i=1;i<=n;i++)if(a[i]>=dec)a[++top]=a[i];
			n=top,ans+=dec;
		}
		for(int i=1;i<=n;i++)if(a[i]>=dec)a[i]-=dec;
	}
	printf("%d\n",ans);
}
