#include<bits/stdc++.h>
using namespace std;
char q[100000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a;
	char b;
	int cnt=1;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		for(int j=0;j<a;j++)
		{
			q[cnt]=b;
			cnt++;
		}
	}
	cnt--;
	int s=0;
	for(int i=1;i<=cnt/2;i++)
	{
		if(q[i]!=q[cnt-i+1])s++;
	}
	cout<<s;
	return 0;
}
