#include<bits/stdc++.h>
using namespace std;
int n;
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long cnt=0;
	for(int i=1;i<=n;i++){
		long long a;
		string c;
		cin>>a>>c;
		cnt+=a;
		while(a--){
			s+=c;
		}
	}
	long long num=0;
	for(int i=0;i<cnt/2;i++){
		if(s[i]!=s[cnt-1-i]) num++;
	}
	cout<<num;
	return 0;
} 
