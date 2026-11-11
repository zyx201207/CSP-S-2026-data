#include<bits/stdc++.h>
using namespace std;
long long n;
long long cnt=0;
long long strl=0;
long long aidx=0;
long long s[200005]={0};
long long a[200005];
char c[200005];
long long ac1(long long x){
	//ask char
	long long idx1=lower_bound(s+1,s+n+1,x)-s;
	return idx1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		strl=strl+a[i];
		s[i]=s[i-1]+a[i];
	} 
	long long idx=1;
	while(idx<=strl/2){
		if(c[ac1(idx)]!=c[ac1(strl-idx+1)]){
			cnt=cnt+min(a[ac1(idx)],a[ac1(strl-idx+1)]);
			idx=idx+min(a[ac1(idx)],a[ac1(strl-idx+1)]);
		}else{
			idx=idx+min(a[ac1(idx)],a[ac1(strl-idx+1)]);
		}
	}
	if(strl%2==1) cout<<cnt-1;
	else cout<<cnt;
	return 0;
}
