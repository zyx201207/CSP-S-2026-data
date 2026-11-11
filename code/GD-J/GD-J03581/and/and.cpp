#include <bits/stdc++.h>
#include <cstring>
using namespace std;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	int a[n];
	//
	int p=0,q=a[0],o[n]={0};
	//
	for(int i = 0;i < n;i++)
	{
		cin >> a[i];
		//
		p = max(p,a[i]);
		q = q and a[i];
		o[a[i]]++;
		//
	}
	
	//
	if(m==1)cout << p;
	else if(m == n)cout << q;
	else if(p <= 4){
		if(m <= o[4]){
			cout << 4;
		}
		else if(m <= o[3]){
			cout << 3;
		}
		else if(m <= (o[3]+o[2])){
			cout << 2;
		}
		else if(m <= o[3]+o[1]){
			cout << 1;
		}
		else{cout << 0;}
	}
	else cout << 1;
	//
	
	return 0;
}
