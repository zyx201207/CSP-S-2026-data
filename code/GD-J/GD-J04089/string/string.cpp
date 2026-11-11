#include<bits/stdc++.h>
using namespace std;
string revers(string s){
	string ss="";
	int l=s.size();
	for(int i=0;i<l;i++){
		ss+=s[l-i];
	}
	return ss;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long int n;
	cin>>n;
	string s="",ss;
	long long int l,L=0;
	for(int i=0;i<n;i++){
		cin>>l;
		cin>>ss;
		for(int j=0;j<l;j++){
			s+=ss;
		}
		L+=l;
	}
	int ans=0;
	int i=0,j=L-1;
	while(j>i){
		if(s[i]!=s[j]) ans++;
		i++;
		j--;
		if(revers(s)==s) break;
	}
	cout<<ans;
	return 0;
} 

