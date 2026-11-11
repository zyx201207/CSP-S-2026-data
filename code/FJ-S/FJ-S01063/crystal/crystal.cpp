#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n>5005){
		int s=1;
		long long o=a[2]-a[1];
		for(int i=1;i<n;i++){
			if(m>=o*i){
				s++;
				m-=o*i;
			}	
		}
	}
	for(int i=2;i<=n;i++){
		long long s=0;
		long long c=0;
		for(int j=i;j>=1;j--){
			c+=a[i]-a[j];
			if(c>m){
				break;
			}
			s++;
		}
		sum=max(s,sum);
	}
	cout<<sum;
	return 0; 
}
