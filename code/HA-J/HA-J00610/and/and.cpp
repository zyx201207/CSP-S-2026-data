#include<iostream>
#include<conio.h>
using namespace std;
int s,a[100000000],c;
char b;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>s>>c;
	for(int i=1;i<=s;i++){
		cin>>a[i];
		if(a[i]=a[i-1]) b=a[i];
	}
	cout<<b;
	return 0;
}