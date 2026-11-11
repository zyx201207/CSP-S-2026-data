#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long cnt=0;
	string a="",b="";
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		for(int j=1;j<=x;j++){
			a=a+y;
			b=y+b;
		}
	}
	for(int i=0;i<a.size()/2+(a.size())%2;i++){
		if(a[i]!=b[i]){
			cnt++;
		}
	}
	cout<<cnt;
}
