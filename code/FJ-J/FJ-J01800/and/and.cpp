#include<bits/stdc++.h>
using namespace std;
int a,b,arr[1000],c=0;
int ip(int b,int d){
	for(int i=d;i<a;i++){
		if(b!=1){
			return arr[i]&arr[ip(b-1,i+1)];
		}
		return i;
	}
}
int main(){
	int c,d;
	cin>>a>>b;
	for(int i=0;i<a;i++){
		cin>>arr[i];
	}
	cout<<ip(b,0);
	return 0;
}
