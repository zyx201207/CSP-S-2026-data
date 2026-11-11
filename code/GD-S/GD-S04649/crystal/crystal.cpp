#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	cin>>a[i];
	sort(a,a+n);
	int sum=0,total=0;
	for(int i=1;i<n;i++){
		for(int j=1;j<=i;j++){
			sum=sum+a[i]-a[i-j];
		}
		if(sum<=m)
		sum=0;
		else{
			cout<<i;
			break;
		}
	}
	return 0;
}
