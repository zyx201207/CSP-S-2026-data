#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travle.in","w",stdin);
	//freopen("travel.out","r",stdout);
	int n,sum=0;
	cin>>n;
	int a[n];
	char b[n];
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		sum+=a[i];
	}
	string s[sum];
	int m=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			s[m]=b[i];
			m++;
		}
	}
	int co=0;
	for(int i=0;i<sum/2;i++)if(s[i]!=s[sum-1-i])co++;
	cout<<co;
	return 0;
}
