#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("string.in","r",stdin);
	//freopen("string1_ex.in","r",stdin);
	freopen("string.out","W",stdout);
	int n;
	cin>>n;
	int a;
	char c[1000000];
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c[i];
	}
	for(int i=1;i<=a;i++)
	{
		cout<<c[i];
	}
	return 0;
}
