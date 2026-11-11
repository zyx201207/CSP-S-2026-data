#include <bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],maxn;
long long read(){
	char c=getchar();
	long long s=0,flag=0;
	while(c!='-'&&(c<'0'||c>'9')) c=getchar();
	if(c=='-'){
		flag=1;
		c=getchar();
	}
	s=c-'0';
	while(c>='0'&&c<='9'){
		c=getchar();
		if(c>='0'&&c<='9') s=s*10+c-'0';
	}
	if(flag==1) return -s;
	else return s;
}
long long cutting(long long l,long long r){
	if(l>=r) return 1;
	long long mid=(l+r)/2;
	long long tmp=0,x=0;
	for(int i=mid;i>=1;i--){
		x++;
		tmp+=(a[mid]-a[i]);
		if(tmp>m){
			x--;
			tmp-=(a[mid]-a[i]);
		}
	}
	return max(x,max(cutting(mid+1,r),(cutting(l,mid)))); 
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+1+n);
	cout<<cutting(1,n);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
