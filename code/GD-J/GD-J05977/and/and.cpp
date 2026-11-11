#include<bits/stdc++.h>
using namespace std;

int n,m,max1=0;
int a[200001];

void f(int t,int ans,int min){
	if(t<=0){
		if(ans>max1)	max1=ans;
		return;
	}
	for(int i=min;i<n;i++){
		f(t-1,ans&a[i],i+1);
	}
}

int main(){
	freopen("and.in","r",stdin);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	f(m,2147483647,0);
	
	freopen("and.out","w",stdout);
	cout<<max1;
	fclose(stdout);
}
