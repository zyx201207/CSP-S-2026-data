#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m; 
	int mm=0;
	for (int i=1;i<=n;i++){
		int a;
		cin>>a;
		if (a>mm){
			mm=a;
		}
	}
	cout<<mm;
} 
