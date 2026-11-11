//GZ-J00212 遵义市第一初级中学 杨铠溢 
#include <bits/stdc++.h>
using namespace std;
char b[2000005];
long long a[2000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	if(n==1){
		cout<<0;
	}
	if(n==2){
		if(b[1]==b[2]){
			cout<<0;
		}else if(a[1]<a[2]){
			cout<<a[1];
		}else if(a[1]>a[2]){
			cout<<a[2];
		}else{
			cout<<a[1];
		}
	}
	return 0;
} 
