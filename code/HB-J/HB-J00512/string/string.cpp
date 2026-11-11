#include<bits/stdc++.h>
using namespace std;
int main(){//HB-J00512
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	string s="",s2="";
	cin>>n;
	long long a[n];
	char b[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>b[i];
		for(int j=1;j<=a[i];j++){
			s+=b[i];
		}
	}
	long long k=s.size();
	for(int i=k-1;i>=0;i--){
		s2+=s[i];
	}
	bool sf=1;
	int num=0;
	for(int i=0;i<k;i++){
		if(s2[i]!=s[i]){
			sf=0;
			num++;
		}
	}
	if(sf==1){
		cout<<"0";
		return 0;
	}
	cout<<num/2;
	return 0;
}
