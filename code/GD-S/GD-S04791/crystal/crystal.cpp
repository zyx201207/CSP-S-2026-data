#include<iostream>
#include<algorithm>
using namespace std;
long long n,m;
const int maxn=5e5+10;
long long a[maxn],ans,b[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]+a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		long long sum=m,f=1;
		for(int j=i-1;j>=1;j--){
			if(a[i]-a[j]<=sum){		
				sum-=a[i]-a[j];f++;
			}
			else break;
		}
		ans=max(ans,f);
	}
	cout<<ans;
	return 0;
} 
