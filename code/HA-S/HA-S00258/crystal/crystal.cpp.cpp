#include <bits/stdc++.h>
using namespace std;
long long a[500005];
long long cha[500005];
int num;
int main(){
	crystal.cpp
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		for(long long j=0;j<i;j++){
			cha[i]+=a[i]-a[i-j];
		}
	}
	for(long long i=1;i<=n;i++){
		if(cha[i]==m and cha[i+1]!=m){
			num=i;
			break;
		} 
		else if(cha[i]==m and cha[i+1]==m){
			num=i;
			for(long long j=1;j<i;j++){
				if(cha[i+j]==m){
					num++;
				}
			}
		}
	}
	cout<<num;
	return 0;
}
