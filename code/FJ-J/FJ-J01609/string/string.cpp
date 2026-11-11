#include<iostream>
#include<string>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long x,num=0;
	cin>>n;
	string a="",y;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		for(int j=0;j<x;j++){
			a+=y;
		}
	}
	for(int i=0;i<a.size()/2;i++){
		if(a[i]!=a[a.size()-i-1]){
			num++;
		}
	}
	cout<<num;
	return 0;
}
