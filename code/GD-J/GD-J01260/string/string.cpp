#include<iostream>
#include<cstdio>
using namespace std;
char c[200001];
int a[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	for(int i=1,j=n;i<j;){
		if(c[i]!=c[j]) ans+=min(a[i],a[j]);
		if(a[i]>=a[j]) a[i]-=a[j],j--;
		else if(a[i]==a[j]) i++,j--;
		else a[j]-=a[i],i++;
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
