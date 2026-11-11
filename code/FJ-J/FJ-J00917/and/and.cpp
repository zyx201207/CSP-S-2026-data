#include<bits/stdc++.h> 
#include<cstdio>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long m,n,a[1000000000],b,c=0;
	cin>>n>>m;
	for(long long i=0;i<n;i++){
    	cin>>b;
    	a[i]=b;
    	c=c+b;
	}
	cout<<c;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
