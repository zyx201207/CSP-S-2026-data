#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n=0;
	long long m=0;
	cin>>n>>m;
	long long a[500001];
	for (int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort (a+1,a+n);
	long long minused[500001]={0};
	for (int i=1;i<n;++i){
		minused[i]=(long long)((long long)a[i+1]-(long long)a[i]);
	}
	int maxnum=1;
	int tempnum=0;
	long long tempsum=0;
	for (int i=1;i<n-maxnum;++i){
		for (int j=-1;j<maxnum-2;++j){
		tempsum-=(long long)minused[i+j];
		}
		for (int j=maxnum;j<n-i+1;++j){
		tempsum+=(long long)(j*(long long)minused[i+j-1]);
		if (tempsum>m||j==n-i) {tempnum=j;
		break;
		}
	}
		if (tempnum>maxnum) maxnum=tempnum;
	}
	cout<<maxnum;
	return 0;
} 
