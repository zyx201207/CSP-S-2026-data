#include<bits/stdc++.h>
using namespace std;
char a[200005];
int main(){
	int n,t=0,s=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		for(int j=1;j<=x;j++){
			a[t]=y;
			t++;
		}
	}
	int l=0,r=t;
	while(l<=r){
		if(a[l]!=a[r]) s++;
		l++,r--;
	}
	cout<<s;
	return 0;
}
