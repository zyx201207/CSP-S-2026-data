#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string S;
	long long n,L=0,sum=0;
	cin >> n;
	for(int i=0;i<n;i++){
		int a;
		cin >> a;
		string c;
		cin >> c;
		L+=a;
		S+=c;
	}
	for(int i=0;i<ceil(L/2);i++)
	{
		if(S[i]!=S[L-i])
		{
			sum++;
		}
	}
	cout << sum;
	return 0;
}
