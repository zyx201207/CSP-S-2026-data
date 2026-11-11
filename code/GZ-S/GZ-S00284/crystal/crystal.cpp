//GZ-S00284 ¿Ó∫∆”Ó
#include<bits/stdc++.h>;
using namespace std;
long long n,m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(long long i=n-1;i>=0;i--){
		long long jl=0;
		for(int j=0;j<n;j++){
			jl+=a[i]-a[j];
		}
		if(jl<=m){
			cout<<i+1;
			break;
		}	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
