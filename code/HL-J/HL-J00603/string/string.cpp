#include<bits/stdc++.h>
using namespace std;
long long n;
char zm[2000100];
long long sl[2000100];
long long l,r;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	s="";
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>sl[i]>>zm[i];
	}

	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=sl[i];j++){
			s+=char(zm[i]);
		}
	}
	l=0;
	r=s.size()-1;
	long long num=0;
	while(l<=r){
		if(s[l]!=s[r]){
			num++;
		}
		l++;
		r--;
	}
	cout<<num;
return 0;
}
