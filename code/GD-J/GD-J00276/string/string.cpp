#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	vector<char> s;
	long long n,a,len_=0;
	char c;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		len_+=a;
		for(int i=0;i<a;i++){
			s.push_back(c);
		}
	}long long w=0;
	for(int i=0;i<len_/2;i++){
		if(s[i]!=s[len_-1-i])
			w++;
	}cout<<w<<endl;
	/* 
	fclose("string.in",stdin);
	fclose("string.out",stdout);*/
	return 0;
} 
