#include<bits/stdc++.h>
using namespace std;
const long long MAX=8e5+10;
long long n,m;
long long mm;
long long a[MAX];
long long s[MAX];
long long ans;
long long maxx;
long long cha[MAX];
long long num;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	mm=m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			num++;
			cha[num]=a[i]-a[j];
			mm-=cha[num];
			if(mm<0)break;
			ans++;
		}
		if(ans>maxx)maxx=ans;
		mm=m;
		memset(cha,0,sizeof(cha));
		num=0;
		ans=0;
	}
	cout<<maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
