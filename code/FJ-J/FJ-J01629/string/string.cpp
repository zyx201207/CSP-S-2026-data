#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n,num=0,number=1,a[200000];
	cin>>n;
	char b[200000],c[1000000];
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		num+=a[i];
		for(int j=1;j<=a[i];j++){
			c[number]=b[i];
			number++;
		}
	}
	int f=0;
	if(num%2==0){
		for(int i=1;i<=num/2;i++){
			if(c[i]!=c[i+num/2]){
				f++;
			}
		}
	}
	else{
		for(int i=1;i<=num/2;i++){
			if(c[i]!=c[i+num/2+1]){
				f++;
			}
		}
	}
	cout<<f<<endl;
	return 0;
}
