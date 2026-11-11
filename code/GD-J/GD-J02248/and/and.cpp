#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;

int n,m;
int a[N];

bool cmp(int a,int b){
	return a<b;
} 

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+n+1,cmp);
	
	if(m==1){
		cout<<a[n];
		return 0;
	}
	
	if(m==2){
		cout<<int(a[n]&a[n-1]);
		return 0;
	}
	
	cout<<a[n];
	return 0;
} 
