#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,k,num=0;
	string s="",str="",ss;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k>>ss;
		for(int j=1;j<=k;j++){
			str+=ss;
		}
		s+=str;
		str="";
	}
	int len=s.size();
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-i-1])num++;
	}
	cout<<num;
	return 0;
}
