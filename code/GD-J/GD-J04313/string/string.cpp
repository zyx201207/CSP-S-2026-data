#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	string s;
	int k=0;
	
	for (int i=1;i<=n;i++){
		int a;
		char c;
		cin >> a;
		cin >> c;
		for (int j=1;j<=a;j++){
			s[++k]=c;
		}
	} 
	int len=s.size();
	int cnt=0;
	for (int i=0;i<=len;i++)
	{
		if(!(s[i]=s[len+1-i])) cnt++;
	}
	cout << cnt+2;
	return 0;
} 
