#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct st{
	long long s;
	char c;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i].s);
		cin>>a[i].c;
	}
	long long ans=0;
	int i=1,j=n;
	while(i<j){
		long long mi=min(a[i].s,a[j].s);
		a[i].s-=mi,a[j].s-=mi;
		if(a[i].c!=a[j].c) ans+=mi;
		if(a[i].s==0) i++;
		if(a[j].s==0) j--;
	}
	cout<<ans;

	fclose(stdin);
	fclose(stdout);
	return 0;
}
