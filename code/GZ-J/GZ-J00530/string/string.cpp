//GZ-J00530 еВЛлбў КывужабЇ
#include<bits/stdc++.h>
using namespace std;
long long n,a,sum;
char b,s[100000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a>>b;
		for(long long j=1;j<=a;j++){
			s[sum]=b;
			sum++;
		}
	}
//	cout<<sum<<endl;
//	for(int f=0;f<sum;f++) cout<<s[f]<<" ";
	long long i=0,j=sum-1,num=0,p=sum/2,pp=sum%2;
//	cout<<p<<" "<<pp<<" "<<i<<" "<<j<<" "<<" ";
	if(pp!=0){
		for(i=0;i<p;i++){
			if(s[i]!=s[j]) num++;
			j--;
		}
	}else{
		for(i=0;i<=p;i++){
			if(s[i]!=s[j]) num++;
			j--;
		}
	}
	cout<<num;
	return 0;
}
