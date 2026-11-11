#include<bits/stdc++.h>
using namespace std;
long long a[500005];
bool abc(int x,int y){
	return x>y;
}
bool flag1=1;
bool flag2=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]-a[i-1]!=1){
			flag1=0;
		}
	}
	long long maxn=max(a[1],a[2]);
	long long minn=min(a[1],a[2]);
	long long num=maxn-minn;
	for(int i=4;i<=n;i++){
		if(a[i]-a[i-1]!=num && a[i-1]-a[i]!=num){
			flag2=0;
//			cout<<"!@#$%^&*()"<<endl;
			break;
		}
	}
			
	if(flag1){
		long long sum=0;
		for(int i=1;i<=n;i++){
			sum+=i;
			if(sum>m){
				cout<<i<<endl;
//				cout<<"!@#$%^&* 1";
				return 0;
			}
		}
		
	}else if(flag2){
		long long sum=0;
		for(int i=1;i<=n;i++){
			sum+=num*i;
			if(sum>m){
				cout<<i<<endl;
//				cout<<"!@#$%^&* 2";
				return 0;
			}
		}
		
	}else{
		sort(a+1,a+n+1,abc);
		for(int i=1;i<=n;i++){
			long long sum=0;
			for(int j=i+1;j<=n;j++){
				sum+=a[i]-a[j];
				if(sum<=m&&j==n){
					cout<<n-i+1<<endl;
					return 0;
				}
			}
		}
	}
	return 0;
}
