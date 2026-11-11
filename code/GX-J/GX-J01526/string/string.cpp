#include<bits/stdc++.h>
using namespace std;
int num=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n;
	cin>>n;
	int a;
	char b;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int ii=1;ii<=a;ii++){
			s+=b;
		}
	}
	int apt=s.size()/2,apt2;
	for(int i=0;i<apt;i++){
		if(s[i]!=s[s.size()-1-i]){
			apt2=s.size()-1-i;
			s[apt2]=s[i];
			num++;
		}
	}
	cout<<num<<endl;
	return 0;
}
