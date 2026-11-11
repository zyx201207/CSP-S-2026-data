#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	long long n,a,num,sum;
	string z,S;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>z[i];
		sum=sum+a;
		if(i>1&&z[i]==z[i-1])
			num=1;
	}
	if(num==1){
		cout<<'0';
		return 0;
	}
	cout<<sum/2;
	return 0;
}
