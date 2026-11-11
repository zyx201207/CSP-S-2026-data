#include<bits/stdc++.h>
using namespace std;
long long int a[200010],n,m,s;
bool cmp(int a,int b){
	return a>b;
} 
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	cout<<a[m];
	return 0;
} 
