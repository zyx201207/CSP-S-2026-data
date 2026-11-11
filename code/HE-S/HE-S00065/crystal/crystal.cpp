#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],s[500010],to[500010],maxx,ans,maxi,maxa;
long long c(long long x,long long k,long long l,long long g,long long cnt){
	long long cha=s[k]-s[l];
	while(x&&g&&l!=0){
		g--;
		cnt++;
		x-=cha;
	}
	if(x) return c(x,k,l-1,to[s[l-1]],cnt);
	else return cnt;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	sort(a+1,a+1+n);
	int w=0;
	for(int i=1;i<=n;i++){
		if(!to[a[i]]){
			s[++w]=a[i];
		}
		to[a[i]]++;
	}
	for(int i=w;i>1;i--){
		long long r=c(m,i,i-1,to[i-1],to[i]);
		maxx=max(maxx,r);
	}
	maxx=max(maxx,to[s[1]]);
	cout<<maxx;
	return 0;
}
