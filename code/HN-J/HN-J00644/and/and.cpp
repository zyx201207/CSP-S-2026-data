#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,a;
	cin>>n>>a;
	long long f[n];
	for(int i=0;i<n;i++){
		cin>>f[i];
	}
	for(int i=0;i<n;i++){
		int t;
		char l;
		while(t==0){
			t=f[i]/2;
			l+=f[i]%2;
		}
		f[i]=l;
	}
	int sum=-1;
	for(int i=0;i<n;i++){
		int b=(f[i] and f[i+1]);
		if(sum<b){
			sum=b;
		}
	}
	cout<<sum;
	return 0;
}
