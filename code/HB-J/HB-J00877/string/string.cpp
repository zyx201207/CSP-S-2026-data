#include<bits/stdc++.h>
using namespace std;
string s="";
int len=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n; cin>>n;
	while(n--){
		int a; char c; cin>>a>>c;
		s.append(a,c); len+=a;
	}
	int num=0;
	for(int i=0;i<=len/2;i++) if(s[i]!=s[len-1-i]) num++;
	cout<<num;
	return 0;
}
