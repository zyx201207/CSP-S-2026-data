#include<bits/stdc++.h>
using namespace std;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	char y;
	long long sum=0,cnt=0,x;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		//cout<<x<<"|"<<y<<"|";
		for(int j=0;j<x;j++){
			a[sum+j]=y;
			//cout<<a[sum+j];
		}
		sum=sum+x;
	}
	/*if(sum%2==1){
		sum++;
	}*/
	for(int i=0;i<sum/2;i++){
		if(a[i]!=a[sum-i-1]){
			cout<<a[i]<<" "<<a[sum+i];
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
