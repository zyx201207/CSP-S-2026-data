#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const long long inf=1e18+5;
long long n,m,ans,cnt=1,a[N],mn=inf;
long long ti;
struct edge{
	long long c,b;
}e[N];
bool cmp(edge b,edge a){
	return a.c>b.c;
}
int main(){
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    if(m==0){
    	cout <<1;
    	return 0;
	}
    for(int i=1;i<=n;i++){
		cin>>a[i];
		e[i].b=a[i];
	}
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
    	long long sum=0;
		for(int j=1;j<=n;j++)sum+=abs(a[i]-a[j]);
		if(sum<=mn)mn=sum,ans=i;
	}
	for(int i=1;i<=n;i++)e[i].c=abs(e[i].b-a[ans]);
	sort(e+1,e+n+1,cmp);
	for(int i=1;i<=n;i++){
		m-=e[i].c;
		if(m==0) {
			cout <<cnt;
			return 0;
		}
		if(m<0){
			cout <<cnt-1;
			return 0;
		}
		cnt++;
	}
    return 0;
}
