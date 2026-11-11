#include<bits/stdc++.h>
using namespace std;

void find(const int m,const int* a,int* max,int start,const int end,int res){
	if(m<=0){
		if(res>*max)*max=res;
		return;
	}
	
	for(int i=start;i<end;i++){
		find(m-1,a,max,i+1,end,res&a[i]);
	}
	return;
}

int main(){
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int max=0;
	for(int i=0;i<n;i++){
	find(m,a,&max,0,n,a[i]);
	}
	cout<<max;
	return 0;
}
