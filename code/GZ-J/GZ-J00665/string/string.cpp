//GZ-J0065,六枝特区岩脚镇中学,周孝熔。
#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long n=0,l=0,sum=0;
	long long a[100000]; 
	string s;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>s[i];
	}
	for(int j=0;j<n/2;j++){
		if(s[j] != s[n-j-1]){
			sum+=1;
		}
	}
	if(a[0]==a[n-1]){
		cout<<sum*a[0];
	}
	else{
		cout<<a[0];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
