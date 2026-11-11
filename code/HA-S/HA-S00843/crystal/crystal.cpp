#include<bits/stdc++.h>
using namespace std;
long long a[55002];int n1,n,cnt=0;long long sum=0;
bool f(long long a1,long long a2){
	return a1<a2;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,f);
	n1=n;long long m1=m,l=1;
	while(l!=0){
		sum=0;cnt=0;
		for(int i=1;i<=n1;i++){
			sum=sum+a[n1]-a[i];
			if(m1<sum){
				n1=n1-1;
				break;
			}
			cnt++;
			if(i==n1){
				cout<<cnt;l=0;
			}
		}
	}
	return 0;
}
