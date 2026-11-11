#include<bits/stdc++.h>
using namespace std;
const long long N=1e7+10;

long long n,kk;
string s,sf;

struct node{
	long long a;
	char c;
}ak[N];

int un(string s,string sf,long long kk){
	long long ans=0;
	for(long long i=0;i<sqrt(kk);i++){
		if(s[i]!=sf[i]){
			ans++;
		}
	}
	return ans;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>ak[i].a>>ak[i].c;
		kk+=ak[i].a;
		for(long long j=1;j<=ak[i].a;j++){
			s+=ak[i].c;
		}
	}
	long long l=s.size()-1;
	for(long long i=0;i<l+1;i++){
		sf+=s[l-i];
	}
	long long oi=un(s,sf,kk);
	cout<<oi;
	return 0;
} 
