#include<bits/stdc++.h>
using namespace std;
char a[2000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,z,s=1,sum=0;
	char x;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>z>>x;
		for(int j=s;j<=s+z;j++){
			a[j]=x;
		}
		s+=z;
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=a[s-i+1]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
