#include<bits/stdc++.h>
using namespace std;

long long a[200005];
int main(){
	//GZ-J00154 遵义市朝阳小学 郑学宇
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,fb=1;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1){
			fb=0;
		}
	}
	if(m==1){
		sort(a+1,a+n+1,greater<long long>());
		cout<<a[1];
	}else if(m==n){
		long long sum=a[1];
		for(long long i=2;i<=n;i++){
			sum=sum&a[i];
		}
		cout<<sum;
	}else{
		sort(a+1,a+n+1,greater<long long>());
		long long sum=a[1];
		for(long long i=2;i<=m;i++){
			sum=sum&a[i];
		}
		cout<<sum;
	}	
	return 0;
} 
