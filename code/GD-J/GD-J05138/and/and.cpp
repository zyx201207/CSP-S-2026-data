#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("airplane.in","string.in"stdin)
	//freopen("airplane.out","string.out"stdout)
	int n,m,a[100],x=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		if(a[i] and m>=x){
			x=a[i];
		}
	}cout<<x;
}


