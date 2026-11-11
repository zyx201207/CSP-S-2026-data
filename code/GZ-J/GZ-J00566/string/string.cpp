//GZ-J00566  七星关东辰实验学校  袁若雪
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,z=0,num=0;
	cin>>n;
	long long a[n];
	char b[n];
	char s[n];
	for(long i=0;i<n;i++){
		cin>>a[i]>>b[i];
		s[i]=b[i];
	}
	for(long i=0;i<n/2;i++){
		if(s[i]==s[n-i-1]){
			z=0;
		}
		if(z!=0){
			break;
		}
	}
	if(z=0){
		num=0;
	}
	else{
		for(long i=0;i<n;i++){
			if(s[i]!=s[n-i-1]){
				num++;
			}
		}
	}
	cout<<num;
	return 0;
}
