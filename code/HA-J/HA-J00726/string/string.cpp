#include<bits/stdc++.h>
using namespace std;
bool hui(string s){
	string t="";
	int j=0;
	for(int i=s.size()-1;i<=0;i--){
		t[j]=s[i];
	}
	return t==s;
}
string s="";
int zh=0;
long long n;
long long sum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		for(int i=1;i<=x;i++){
			s+=c;
		}
	}
	long long lens=s.size();
	long long j=lens;
	for(int i=0;i<lens;i++){
		if(s[i]!=s[j]){
			s[j]=s[i];
			j--;
			sum++;
		}
	}
	cout<<sum<<endl;
	return 0;
}
