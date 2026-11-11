#include <bits/stdc++.h>
using namespace std;
string s1;
int main(){
	freopen("string.in.txt","r",stdin);
	freopen("string.out.txt","w",stdout);
	int n;
	cin>>n;
	long long s=0;
	for(int i=0;i<n;i++){
		long long r;
		string t;
		cin>>r>>t;
		for(long long k=0;k<r;k++){
			s1=s1+t;
		}
	}
	string s2=s1;
	reverse(s1.begin(),s1.end());
	for(int i=0;i<n;i++){
		if(s1[i]!=s2[i]){
			s++;
		}
	}
	cout<<s;
	return 0;
}
