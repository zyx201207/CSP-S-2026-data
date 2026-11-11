#include<bits/stdc++.h>

using namespace std;

long long n,m;
long long a[500100];

long long check(int x){
	long long sum=0;
	for(int i=0;i<x;i++){
		sum+=a[x]-a[i];
	}
	return sum;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n); 
	int l=0,r=n-1,mid=(l+r)/2;
	while(r>=l)
	{
		mid=(l+r)/2;
		if(check(mid)<=m) l=mid+1;
		else r=mid-1;
	}
	cout << r+1 << endl;
	
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
