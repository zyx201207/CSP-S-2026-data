#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    long long n=0,m=0,ans=0;
    cin>>n;
    int a[n]={};
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
  	sort(a,a+n+1);
  	int sum=a[n] and a[n-1];
  	cout<<sum;
	
	return 0;
}

