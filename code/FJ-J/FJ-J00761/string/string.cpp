#include<bits/stdc++.h>
#include<string>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string S;
	char t;
	long long n,m,l=0,l1=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m>>t;
		S=S+string(m,t);
		l+=m;
	}
	bool q=0;
	if(l%2==1)q=1;
	for(long long i=0;i<l/2;i++){
		if(S[i]!=S[l-i-1])l1++;
	}
	cout<<l1<<endl;
	return 0;
}
