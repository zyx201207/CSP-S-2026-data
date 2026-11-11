#include<bits/stdc++.h>
using namespace std;
long long n,m,sum=1;
long long a[100005];
long long b[100005];
int d(int x){
	long long num=0;
	long long h=m;
	for(int i=0;i<n;i++){
		b[i]=abs(a[x]-a[i]);
	}
	sort(b,b+n);
	for(int i=0;i<n;i++){
		if(h-b[i]>=0){
			h-=b[i];
			num++;
		}
	}
	return num;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		if(sum<d(i)){
			sum=d(i);
		}
	}
	cout<<sum;
	return 0;
}
