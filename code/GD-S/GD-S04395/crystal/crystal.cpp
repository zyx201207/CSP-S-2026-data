#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,m;
long long a[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	long long cnt=0;
	long long l=1,r=1,num=0;
	long long ans=0;
	for(long long i=1; i<=n; i++){
		cnt+=a[i];
		num++;
		if(i!=1)r++;
	//	if(i!=1&&abs(a[i]*num-cnt)<=m)r++;
		while(abs(a[i]*num-cnt)>m&&l<r){
			cnt-=a[l];
			num--;
			l++;	
		}	
	//	cout<<l<<"  "<<r<<" "<<cnt<<endl;	
		ans=max(r-l+1,ans);
	}
	cout<<ans;
}
