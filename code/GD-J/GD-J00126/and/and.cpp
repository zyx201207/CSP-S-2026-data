#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long ans=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
    } 
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n]<<endl;
		return 0;
	}else if(m==2){
		long long mx=0;
		for(int i=1;i<=n;i++){
		   for(int j=1;j<=n;j++){
		   	if(i!=j) mx=max((a[i]&a[j]),mx);
		   }
		} 
		cout<<mx<<endl;
		return 0;
	}else if(m==n){
		long long cnt=a[1];
		for(int i=2;i<=n;i++){
			cnt=(cnt&a[i]);
		}
		cout<<cnt<<endl;
		return 0;
	}
	long long mx=-1;
	for(int i=1;i<=n-m;i++){
		long long k=a[i];
		for(int j=i+1;j<=i+m;j++){
			k=(k&a[j]);
		}
		mx=max(mx,k);
	}
	cout<<mx<<endl;
	return 0;
}

