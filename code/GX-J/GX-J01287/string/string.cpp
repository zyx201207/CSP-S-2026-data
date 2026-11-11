#include<bits/stdc++.h>
using namespace std;
long long n,ans;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n){
		long long a;
		char c;
		cin>>a>>c;
		for(long long i=0;i<a;i++){
			s+=c; 
		}	
		n--;
	}
	long long lens=s.size();
	for(long long i=0;i<lens/2;i++){
		if(s[i]!=s[lens-1-i]){
			ans+=1;
		}
	}
	cout<<ans;
	return 0;
}
