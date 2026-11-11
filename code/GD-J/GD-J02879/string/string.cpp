#include<bits/stdc++.h>
using namespace std;
long long c[105];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long a[n+5];
	char b[n+5];
	long long num=0,sum=0,tool=0;
	int toool;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		toool=b[i]+1-1;
		c[toool]+=a[i];
	}
	for(int i=97;i<=112;i++){
		if(c[i]>0){
			tool++;
		}
		num+=c[i]%2;
		sum+=c[i]%2;
		sum=sum%2;
		
	}
	
	
	if(tool==1){
		cout<<0;
		return 0;
	}
	if(sum%2==1){
		cout<<num+1;
		return 0;
	}
	cout<<num;
	return 0;
}
