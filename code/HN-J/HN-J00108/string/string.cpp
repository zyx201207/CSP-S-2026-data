#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s,b;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	int l=-1;
	for(int i=s.size()-1;i>=0;i--){
		b[++l]=s[i];
	}
	long long num=0;
	for(int i=0;i<=(s.size()+1)/2-1;i++){
		if(b[i]!=s[i]) num++;
	}
	cout<<num;
	return 0;
}
