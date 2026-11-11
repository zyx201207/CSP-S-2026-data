#include<iostream>
using namespace std;
long long a[999999]; 
long long b[999999];
long long c[999999];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=0;i<n;++i){
		cin>>a[i];
		b[a[i]]++;
		if(b[i]>1){
			for(long long j=0;j<i;++j){
				a[j]=0;
			}
		}
	}
	for(long long i=0;i<n;++i){
		b[a[i]]++;
		if(b[i]>1){
			for(long long j=0;j<i;++j){
				a[j]=0;
			}
		}
	}
	for(long long i = 0;i < n;++i){
		c[b[i]]++;
	}
	for(long long i=1;i<m;++i){
		cout<<c[i]<<" ";
	}
	return 0;
}
