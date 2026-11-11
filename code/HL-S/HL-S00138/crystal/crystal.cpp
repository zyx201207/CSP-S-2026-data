#include<bits/stdc++.h>
using namespace std;
const int N=500001;
long long n,m,ans=INT_MIN;
long long b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	sort(b,b+n);
	for(long long j=0;j<n;j++){
		long long a[n+1];
		for(int z=0;z<n;z++){
			a[z]=b[z];
		}
		long long l=m,mid=a[j],ans_x=0;
		for(long long i=n-1;i>=0;i--){
			if(l==0){
				break;
			}
			if(mid>=a[i] && l-(mid-a[i])>=0){
				l-=mid-a[i];
				a[i]=mid;
			}
		}
		for(long long i=0;i<n;i++){
			if(a[i]==mid){
				ans_x++;
			}
		}
		ans=max(ans,ans_x);
	}
	cout<<ans;
	return 0;
}