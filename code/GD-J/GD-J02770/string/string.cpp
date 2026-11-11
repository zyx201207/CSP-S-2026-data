#include<bits/stdc++.h>
using namespace std;
char s[6000000000];		
long long n,nm,g=0;
bool f=false;
char c;
long long l;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>l;
		cin>>c;
		for(long long j=0;j<l;j++){
			s[nm]=c;
			nm++;
		}
	}
	for(long long i=0;i<=nm/2;i++){
		if(s[i]!=s[nm-i-1]){
			g++;
		}
	} 
	cout<<g;
	return 0;
}
