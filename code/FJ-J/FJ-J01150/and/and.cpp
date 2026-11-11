#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
char a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m>n/2){
		cout<<0;
	}else if(m==1){
		cout<<a[n];
	}else if(m==2){
		cout<<a[n-1];
	}else{
		cout<<a[n-m];
	}
	return 0;
}
