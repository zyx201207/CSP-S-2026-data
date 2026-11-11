#include<bits/stdc++.h>
using namespace std;
vector<int>a;
int max1=0;
int n,m;
void f(int x){
	for(int i=x;i<n;i++){
		if((a[x-1] and a[i])>max1)max1=(a[x-1] and a[i]);
	}
} 
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		a.push_back(k);
	}
	if(m==n){
		int max=0;
		for(int i=0;i<n;i+=2){
			if(i>=n)break;
			max+=a[i] and a[i+1];
		}
		cout<<max;
		return 0;
	}
	if(m==1){
		int max=0;
		for(int i=0;i<n;i++){
			if(a[i]>max)max=a[i];
		}
		cout<<max;
	}
	for(int i=1;i<n;i++){
		 f(i);
	}
	cout<<max1;
	//for(int i=2;)
} 
