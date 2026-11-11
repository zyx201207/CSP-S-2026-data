#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	if(n%2==0){
		cout<<a[n/2];
	}else{
		cout<<a[n/2+1];
	}
	return 0; 
}
