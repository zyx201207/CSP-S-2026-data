#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+9;
long long a[N];
char p[N];
long long sum=0,ans=0;
long long k=0,l=0,a1,a2;
bool r=false;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		cin>>p[i];
	}
	for(long long i=1;i<=sum;i++){
		k=0,l=0;
		for(int s=0;s<=n;s++){
			if(a[s]>0&&k==0)k=s;
			if(a[n-s]>0&&l==0)l=n-s;
			if(l!=0&&k!=0)break;
		}
		if(l==0&k==0)break;
		a1=a[k],a2=a[l];
		if(p[k]!=p[l]){
			ans+=min(a1,a2);
			a[k]-=min(a1,a2);
			a[l]-=min(a1,a2);
		}else{
			a[k]-=min(a1,a2);
			a[l]-=min(a1,a2);
		}
	}
	cout<<ans;
	return 0;
}

