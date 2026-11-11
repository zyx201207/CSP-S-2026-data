#include<bits/stdc++.h>
using namespace std;

//¿ª longlong!!!!! 

long long n,m;
long long a[500005]; 
long long ans=1,sum=0;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	a[n]=a[n-1];
	long long index0=n-1;
	for(long long i=n-1;i>=0;i--){
		sum-=(a[i+1]-a[i])*(i-index0+1);
		while(sum<=m&&index0>=0){
			index0--;
			if(index0>=0){
				sum+=a[i]-a[index0];
			}
			ans=max(ans,i-index0);
		}
	}
	cout<<ans;
    return 0;
}

