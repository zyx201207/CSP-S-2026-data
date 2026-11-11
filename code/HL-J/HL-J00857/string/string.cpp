#include<bits/stdc++.h>
using namespace std;
long long a[2000000],b[2000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","r",stdout);
	long long n,s=1;
	long long cnt=0,sum=0,num=0,ans=0,lyl;
	cin>>n;
	while(n--){
		long long x;
		char y;
		cin>>x>>y;
		a[s]=y;
		b[s]=x;
		num+=x;
		s++;
	}
	char x1=a[1];
	for(int i=1;i<=n;i++){
		if(a[i]==x1){
			sum++;
		}
	}
	if(sum==n){
		sum=0;
		lyl=0;
	}
	else{
		for(int j=n;j>=1;j--){
			for(int i=1;i<=n;i++){
				if(a[i]==a[j]){
					sum++;
				}
				if(b[i]==b[j]){
					cnt++;
				}
			}
		}
		if(sum==n&&cnt==n){
			lyl=0;
		}
		else{
			if(num%2!=0){
				lyl=(num-1)/2;
			}
			else{
				lyl=num/2;
			}
		}
	}
	cout<<lyl;
	return 0;
}