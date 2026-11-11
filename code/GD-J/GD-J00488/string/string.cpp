#include<bits/stdc++.h>
using namespace std;
int n;
long long len=0;
vector<long long>a;
vector<long long>al;
vector<long long>ar;
vector<char>c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	a.resize(n+1,0);
	al.resize(n+1,0);
	ar.resize(n+1,0);
	c.resize(n+1,0);
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&a[i],&c[i]);
		al[i]=len+1;
		len+=a[i];
		ar[i]=len;
	}
	int l=1,r=n;
	long long ans=0,lnow=1,rnow=len,d;
	//printf("l=%d,r=%d,lnow=%lld,rnow=%lld\n",l,r,lnow,rnow);
	while(l<r){	
		d=min(ar[l]-lnow,rnow-al[r]);
		if(c[l]!=c[r]){//不同需要涂成相同 
			ans+=d+1;
		}
		if(d==ar[l]-lnow){//lnow剩余更少 
			l++;
			lnow=al[l];
			rnow=len+1-lnow;
		}
		else{//rnow剩余更少
			r--;
			rnow=ar[r];
			lnow=len+1-rnow;
		}
		//printf("l=%d,r=%d,lnow=%lld,rnow=%lld\n",l,r,lnow,rnow);
	}
	printf("%lld",ans); 
}
