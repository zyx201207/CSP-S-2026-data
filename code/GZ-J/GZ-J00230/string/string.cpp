// Gz-J00230 黔西市思源实验学校 许邴淳
#include<iostream>
#include<string>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","r",stdout);
	int n;
	cin>>n;
	int a[n];
	int sum=0;
	char b[n];
	string x;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		for(int j=0;j<a[i];j++){
			x+=b[i];
		}
	}
	for(int i=0;i<x.size()/2;i++){
		if(x[i]!=x[n-i]){
			sum++;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
    return 0;
} 
