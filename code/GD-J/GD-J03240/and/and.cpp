#include<bits/stdc++.h>
using namespace std;
struct sb{
	long long x,y;
}a[2000005];

long long f(long long n){
	long long cnt=0;
	while(n){
		if(n%2==1)cnt++;
		n/=2;
	}
	return cnt;
}
bool ff(long long n){
	while(n%2==0)n/=2;
	if(n==1)return 0;
	return 1;
}
bool cmp(sb xx,sb yy){
	if(xx.y==yy.y)return xx.x>yy.x;
	return xx.y>yy.y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
		a[i].y = f(a[i].x);
	}
	if(n==m){
		long long cnt=a[1].x;
		for(int i=2;i<=m;i++){
			cnt&=a[i].x;
		}
		cout<<cnt;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	long long cnt=a[1].x;
	long long maxn=-1;
	for(int i=2;i<=n;i++)maxn = max(maxn,a[i].x);
		for(int i=2;i<=m;i++){
			if(!ff(a[i].x) && a[i].x>=maxn){
				m++;
				continue;
			}
			cnt&=a[i].x;
		}
	
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
