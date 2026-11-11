#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long a[n+1];
	long long b[n+1];
	int max=0,num=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			num=a[i]&b[j+1];
			if(num>max) max=num;
		}
	}
	cout<<max;
	return 0;
}
