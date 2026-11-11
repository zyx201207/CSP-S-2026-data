#include<bits/stdc++.h>
using namespace std;
long long n,a,k,k_;
char b;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int i=0;i<a;i++)
		    s[k+i]=b;
		k+=a;
	}
	for(int i=0;i<k/2;i++) if(s[i]!=s[k-i-1]) k_++;
	cout<<k_;
	fclose(stdin);fclose(stdout);
	
	return 0;
}
