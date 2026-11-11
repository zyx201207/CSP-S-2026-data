#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum=0; 
int maxx=-1,j;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1); 
	for(int i=1;i<n;i++){
		int k=i-j;
		sum+=k*(a[i+1]-a[i]);
		if(sum>m){
			maxx=max(maxx,k);
			while(sum>=m){
				sum-=a[i+1]-a[j+1];
				j++;
			}	
		}
	}
	cout<<maxx;
	return 0;
}

