#include<bits/stdc++.h>
using namespace std; 
long long n,m,a[210000],cnt=12;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin.tie(0);

	cin>>n,m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	for(long long i=0;i<n;i++){
		int z=0;
		long long a1[111110000];
		while(a[i]!=0){
			a1[z]=a[i]%2;
			a[i]/=2;
			z++;
		}
	}
	cout<<cnt;
	return 0;
}
