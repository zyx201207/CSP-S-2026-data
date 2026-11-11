#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],x=1,sum=1,p;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
//	for(long long i=1;i<=n;i++){
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
	while(m>=0&&x<n){
		if(a[x]<a[x+1]){
			p=a[x+1]-a[x];
			m-=x*p;
//			cout<<"p:"<<p<<" m:"<<m<<" ";
			if(m<0){
//				cout<<"out"<<endl;
				break;
			}
			sum++;x++;
		}
		else if(a[x]==a[x+1]){
			sum++;x++;
		}
//		cout<<"sum:"<<sum<<" x:"<<x<<endl;
	}
	if(m>0){
		sum=max(m%n,n-m%n);
	}
	cout<<sum;
	return 0;
}
