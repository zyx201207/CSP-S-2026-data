#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200100],sum1,b[34],sum2;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int x=a[i],j=0;
		while(x){
			if(x|2)b[j]++;
			j++;
			x>>=1;
		}	
	}
	for(int i=34;i>=0;i--){
		if(b[i]>=m&&sum2<m){
			sum1+=pow(2,i);
			sum2++;
		}
	}
	cout<<sum1;
}
