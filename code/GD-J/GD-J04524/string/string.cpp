#include<bits/stdc++.h>
using namespace std;
long long n,x[20005];
char t[20005];
string s;
bool ishuiwen(string s){
	string tmp=s;
	reverse(s.begin(),s.end());
	return tmp==s;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>t[i];
		for(int j=1;j<=x[i];j++){
			s+=t[i];
		}
	}
	long long pos=0,len=s.length()-1,ans1=0,ans2=0,ans;
	string tmps=s;
	while(!ishuiwen(s)){
		s[pos]=s[len-pos];
		pos++;
		ans1++;
	}
	pos=0;
	while(!ishuiwen(tmps)){
		tmps[len-pos]=tmps[pos];
		pos++;
		ans2++;
	}
	ans=min(ans1,ans2);
	cout<<ans;
	return 0;
} 
