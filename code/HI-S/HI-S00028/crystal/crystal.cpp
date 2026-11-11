#include<bits/stdc++.h>
using namespace std;

const int N = 500005;
long long a[N];
long long sr;
int n;
long long m,ans;
int ma;
bool dc;
int z; 

int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(i==2) z==a[i]-a[i-1];
		if(i>1 && a[i]-a[i-1]!=z) dc=true; 
	}
	if(!dc){
		long long jl=0;
		int cs=0;
		for(int i=1;jl<=m;i+=z) jl+=i,cs++;
		printf("%lld",min(n,cs));
		return 0;
	}
	sort(a+1,a+n+1);
	int l=1,r=1;
	ma=1;
	while(l<=n && r<=n){
		if(ans<=m){
			ma=max(r-l+1,ma);
		}
		long long kn=ans+(a[r+1]-a[r])*(r-l+1);
		if(kn>m){
			l++;
			ans=ans-(a[r]-a[l]);
		}else{
			r++;
			ans=kn;
		}
	}
	printf("%d",ma);
	return 0;
}

