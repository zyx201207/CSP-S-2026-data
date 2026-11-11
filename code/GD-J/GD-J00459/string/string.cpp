#include<bits/stdc++.h>
using namespace std;
long long sum;
struct str{
	long long a;
	char c;
	string s2;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdin);
	cin.tie(0);
	long long n;
	cin>>n;
	string s;
	str m[n+1];
	for(long long i=1;i<=n;i++){
		cin>>m[i].a>>m[i].c;
		for(long long j=1;j<=m[i].a;j++){
			m[i].s2+=m[i].c;
		}
	}
	for(long long i=1;i<=n;i++){
		s+=m[i].s2;
	}
	string s1;
	int l=s.size();
	for(long long i=l-1;i>=0;i--){
		s1+=s[i];
	} 
	for(long long i=0;i<l;i++){
		if(s[i]!=s1[i]){
			sum++;
		}
	}
	cout<<sum/2;
	return 0;
} 
