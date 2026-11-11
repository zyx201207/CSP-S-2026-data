#include<bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long y){
	return x>y;
}
long long n,m,a[500005],b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long mb=m,l=m/n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long maxx=1;
	for(long long i=a[1];i<=(a[n]+l);i++){
		mb=m;
		long long cnt=0;
		for(long long j=1;j<=n;j++){
			b[j]=a[j]-i;
			if(b[j]>0) b[j]=-1000000000000000000;
		}
		sort(b+1,b+1+n,cmp);
		while(mb>0){
			for(int j=1;j<=n;j++){
				mb+=b[j];
				if(mb<0) break;
				cnt++;
			}
		}
		maxx=max(maxx,cnt);
	}
	cout<<maxx;
	
	return 0;
}

