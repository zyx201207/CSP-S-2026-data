#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],maxn=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		int sum=1,k=m,h=a[i],y=i-1;
		while(k>=0){
			if(y<=0)break;
			sum++;
			y--;
			h=a[i];
			h-=a[i]-a[y];
			k-=a[i]-a[y];
		}
		if(sum>=maxn)maxn=sum;
	}printf("%d",maxn);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
