#include<bits/stdc++.h>
using namespace std;
int b,sum,n[1000],num;
string a[100000],m[1000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>b;
	for(int i=1;i<=b;i++){
		cin>>n[i];
		cin>>m[i];
		for(int j=1;j<=n[i];j++){
		    a[j]==m[i];
	    }
	}
	for(int i=1;i<=b;i++){
		num+=n[i];
	}
	sum=0;
	if(num%2==0){
		for(int i=1;i<=num/2;i++){
			if(a[i]!=a[num-i+1]){
				sum++;
			}
		}
	}
	else{
		for(int i=1;i<=(num-1)/2;i++){
			if(a[i]!=a[num-i+1]){
				sum++;
			}
	    }
	}
	cout<<sum;
	return 0;
} 
