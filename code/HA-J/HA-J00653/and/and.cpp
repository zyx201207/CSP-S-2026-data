#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
int a[N];
string s[N];
int b[N];
long long ans=0;
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1){
			flag=0;
		}
	}
	if(flag){
		int k=log2(n+1);
		cout<<pow(2,k-1);
	}else{
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
	}
	return 0;
}
/*
5 3
31 3 1 15 7

*/