#include<bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int a[n];
	cin>>a[0];
	long long t=1,d=0,s=0;
	sort(a,a+n,cmp);
	int f;
	for(long long i=1;i<n;i++){
		cin>>a[i];
		if(a[i]==a[i-1]){
			t++;
		}else{
			if(t>=d){
				d=t;
				s=a[i-1];
				f=i-t-1;
			}
			t=1;
		}
	}
	if(t>=d){
		d=t;
		s=a[n-1];
		f=n-t-1;
	}
	long long sum=d;
//	cout<<sum<<endl;
//	for(long long i=0;;i++){
//		if(a[i]==s){
//			t=i-1;
//			break;
//		}
//	}
	for(long long i=f;i>=0;i--){
		if(m>=s-a[i]){
			m-=s-a[i];
			sum++;
//			cout<<sum<<' '<<m<<endl;
		}
	}
	cout<<sum;
	return 0;
}
