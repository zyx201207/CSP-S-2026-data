#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,s=0,x=0,y=0;
	cin>>n;
	int a[10000000]={};
	string c[100000];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=2;i<=n;i++){
		if(c[i-1]==c[i]){
			s++;
		}
	}
	if(s==n-1){
		cout<<"0";
		return 0;
	}
	if(n%2==0){
		
	}
	return 0;
}
