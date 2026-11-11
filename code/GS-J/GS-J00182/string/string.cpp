#include<bits/stdc++.h>
using namespace std;

int n=0;
char s[100000]={};
int pd(int len){
	int sam=0;
	for(int i=0;i<len;i++){
		if(s[i]==s[len-i-1]){
			sam++;
		}
	}
	if(sam==len){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long len=0;
	for(long long i=0;i<n;i++){
		long long b;
		char a;
		cin>>b>>a;
		for(long long j=0;j<b;j++){
			s[len]=a;
			len++;
		}
	}
	//输入s
	int sum=0,tmp=0,temp=0;
	while(tmp!=1){
		if(pd(len)){
			tmp=1;
		}//检查回文，停止条件
		if(s[temp]!=s[len-temp-1]){
			s[len-temp-1]=s[temp];
			sum++;
		}
		temp++;
	
	}
	cout<<sum;

	return 0;
}
