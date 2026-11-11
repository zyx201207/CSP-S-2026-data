#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a[200002],c,d=0;
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	for(long long i=0;i<n;i++){
		for(long long j=i+1;j<n;j++){
			c=a[i]&a[j];
//			cout<<c<<endl;
			if(c>d){
				d=c;
			}
		}
	}
	cout<<d;
	return 0;
}

