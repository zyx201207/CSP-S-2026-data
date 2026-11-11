#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	char a;
	long long n,b;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b>>a;
		for(int j=1;j<=b;j++){
			s+=a;
		}
	}
	long long l=s.size(),sum=0;
	for(int i=0;i<l/2;i++){
		if(s[i]!=s[l-1-i])sum++;
	}
	cout<<sum;
	return 0;
}

