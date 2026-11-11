#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[50005],b[50005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int sum=-1;
	sort(a,a+n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		long long mm=m;
		int sum1=0;
		for(int j=0;j<n;j++){
			b[j]=abs(a[i]-a[j]);
		}
		sort(b,b+n);
		int ii=0;
		while(mm>=b[ii]){
			sum1++;
			mm-=b[ii];
			ii++;
		}
		sum=max(sum,sum1);
	}
	cout<<sum;
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
