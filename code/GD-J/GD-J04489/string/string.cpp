#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a[200005],ant=0;
	char b[200005];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]!=b[i-1]) ant++;
	}
	cout<<ant;
	
	return 0;
}
