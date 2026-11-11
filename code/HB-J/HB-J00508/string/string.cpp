#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
string s;
ll sum;
int main(){
	//freeopen("string.in","r",stdin);
	//freeopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{	
		int x ;
		char y;
		cin >> x >> y;
		for(int i=0;i<x;i++)
		{
			s+=y;
		}
	
	}
	ll p=s.size();
	for(int i=0,j=p;i<j;i++,j--)
	{
		if(s[i]!=s[j])
			sum++;
	}
	cout << sum;
	return 0;
}
