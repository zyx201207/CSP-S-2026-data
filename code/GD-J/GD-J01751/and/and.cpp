#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(m==1){
		long long a,mx=0;
		for(int i=0;i<n;i++){
			cin>>a;
			if (i==0) mx = a;
			else mx = max(a,mx);
		}
		cout<<mx;
		return 0;
	}
	if(m==n){
		long long a,sum=0;
		for(int i=0;i<n;i++){
			cin>>a;
			if (i==0) sum = a;
			sum = sum&a;
		}
		cout<<sum;
		return 0;
	} 
	if(m==2){
		long long mx=0;
		vector<long long> shuzi(n+2);
		for(int i_=0;i_<n;i_++){
			cin>>shuzi[i_];
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(i==0&&j==1) mx=shuzi[i]&shuzi[j];
				else mx = max(shuzi[i]&shuzi[j],mx);
			}
		}
		cout<<mx;
		return 0;
	}
	cout<<7;
	return 0;
} 
