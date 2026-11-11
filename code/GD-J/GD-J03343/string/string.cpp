#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	string s = "";
	long long m  = 0;
	for(long long i = 0;i<n;i++){
		long long a;
		string s1;
		cin>>a;
		cin>>s1;
		for(long long j = 0;j<a;j++){
			s+=s1;
		}
	}
	long long c2 = s.size();
	if(c2%2==0){
		m = c2/2;
	}else{
		m = c2+1;
		m = m/2;
	}
	cout<<m<<endl;
	long long c = 0;
	for(long long i = 0;i<m;i++){
		for(long long j = s.size();j>m;j--){
			if(s[i]!=s[j]){
				c++;
			}
		}
	}
	cout<<c;
	return 0;
}
