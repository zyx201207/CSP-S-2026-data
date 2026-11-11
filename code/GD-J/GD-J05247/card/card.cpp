#include<bits/stdc++.h>
using namespace std;
long long a[2000001],b[300005],sum,m;
long long n;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		long long w;
		cin>>w;
		if(w!=b[sum]){
			a[w]++;
			sum++;
			b[sum]=w;
		}
	}
	for(long long i=1;i<=sum;i++){
		cout<<a[b[i]]<<" ";
	} 
	return 0;
}
