#include<bits/stdc++.h>
using namespace std;
int n,cnt=0;
string s;
queue <string> q;
bool check(string s){
	for(int l=0,r=s.size()-1;r!=l;r--,l++)
	{
		if(s[l]!=s[r])
			return false;
		else
			return true;
	}
}
void change(){
	for(int l=0,r=s.size()-1;r!=l;r--,l++)
			if(s[l]!=s[r])
				cnt++;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		int a;
		string c;
		cin>>a>>c;
		while(a--)
			s+=c;
	}
	if(!check(s))
		change();
	cout<<cnt;
	return 0;
}
