#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a,f=0,e=0;
	char c;
	cin>>n;
	char sum[n];
	for(int i=0;i<n;i++)
	{
		cin>>a>>c;
		sum[i+a]+=(a*c);
	}
	for(int i=0;i<n;i++) {
		if(sum[i]==sum[n-1-i]){
			e++;
		}
	}
	if(n%2==0){
		if(n/e==2){
			cout<<"0";
			return 0;
		}
	}
	else{
		if((n+1)/e==2){
			cout<<"0";
			return 0;
		}
	} 
	for(int i=0;i<n;i++){
		if(sum[i] !=sum[n-1-i]){
			f++;
		}
	}
	cout<<f;
	return 0;
}
