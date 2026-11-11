#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m;
int a[500005]; 
long long sum;
int main(){
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool tc=true,tch=true;
	cin>>a[0];
	for(int i=1;i<n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1]){
			tc=false;
		}
		if(abs(a[i]-a[i-1])!=1){
			tch=false;
		}
		sum+=a[i];
	}
	if(tc){
		if(m>n) cout<<max(m%n,n-m%n);
		else cout<<max(m,n-m);
		return 0;
	}
	sum/=n;
	if(tch){
		int cnt=1;
		for(int i=1;i<n;i++){
			if((m-i)<=0) break;
			m-=i;
			cnt++;
		}
		cout<<cnt;
		return 0;
	}
	sort(a,a+n);
	int mid=n/2;
	int mn=a[mid];
	for(int i=mid;i>=0;i--){
		m-=(mn-a[i]);
		a[i]=mn;
	}
	int cnt=0;
	for(int i=0;i<n;i++){
		if(a[i]==mn) cnt++;
	}
	cout<<cnt;
	return 0;
}
