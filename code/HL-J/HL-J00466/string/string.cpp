#include <bits/stdc++.h>
using namespace std;
string s,d;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,num=0,le=0;
	cin>>n;
	int a;
	string c;
	for (int i=1;i<=n;i++){
		cin>>a>>c;
		for (int j=1;j<=a;j++){
			s+=c;
		}
	}
	for (int i=s.size()-1;i>=0;i--){
		d+=s[i];
	}
	if (s.size()%2==0){
		le=s.size()/2;
	}
	else{
		le=s.size()/2+1;
	}
	for (int i=0;i<le;i++){
		if (s[i]!=d[i]){
			num++;
		}
	}
	cout<<num;
	return 0;
}
