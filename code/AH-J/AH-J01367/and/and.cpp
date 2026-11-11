#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	/*int a=31,b=15,c=7;
	int t=a&b&c;
	cout<<t;*/
	int n,m,maxx=INT_MIN;
	cin>>n>>m;
	int a[n],t[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
    for(int i=0;i<n;i++){
		t[i]=a[i]&a[i+1];
		if(t[i]>maxx)
		{
			maxx=t[i];
		}
	}
	cout<<maxx;
	return 0;
} 
