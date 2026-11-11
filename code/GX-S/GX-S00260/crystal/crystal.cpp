#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("crystal.in","r",stdin);
   freopen("crystal.out","w",stdout);
   int n,m;
   int sum=0;
   int sum1=0;
   int sum2=0;
   cin>>n>>m;
   int a[n+5]={0};
   for(int i=0;i<n;i++){
	   cin>>a[i];
	}
	int b[n+5]={0};
	sort(a,a+n);
	sum=n/2;
	for(int i=0;i<n;i++){
		if((a[sum]-a[i])>0){
			b[i]=(a[sum]-a[i]);
		}else{
			b[i]=(a[sum]-a[i])*-1;
		}
	}
	sort(b,b+n);
	for(int i=0;i<n;i++){
		sum1+=b[i];
		if(sum1<=m){
			sum2++;
		}
	}
	cout<<sum2;
   return 0;
}
