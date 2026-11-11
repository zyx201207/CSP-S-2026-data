#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,k=1,cha=0,max1=-1;
	cin>>n>>m;
	vector<int> v(n+1);
	for(long long i=0;i<n;i++) cin>>v[i];
	
	
	for(long long j=n-1;j>0;j--){
		for(long long l=j-1;l>=0;l--){
			if(cha+v[j]-v[l]>m){
				break;
			}
			cha+=v[j]-v[l];
			k++;
		}
		if(max1<k){
			max1=k;
		}
		k=1;
		cha=0;
	}
	
	
	cout<<max1; 
} 
