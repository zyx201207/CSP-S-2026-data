#include <bits/stdc++.h>
using namespace std;
bool fanzhuang(string a)
{
	string b;
	int size=a.size();
	for(int i=size-1;i>=0;i--)
	{
		b+=a[i];
	}
	if(a==b) return true;
	else return false;
}
/*
int panduan(string a){
	long long minn=1000000000000;
	int size=a.size();
	int cnt=0;
	int b=fanzhuang(a);
	for(int i=0;i<=size-1;i++){
		
	}
	
}
*/
string gebie,ste,fan;
int main()
{
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	long long n,a;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> a >> ste;
		for(int j=0;j<a;j++)
		{
			gebie+=ste;
		}
	}
	if(fanzhuang(gebie)) cout << 0;
	else
	{
		cout << 2;
		//panduan(gebie);
	}
	
	return 0;
}
