#include <bits/stdc++.h>
using namespace std;
string s="",sf="";
char c;
int n;
long long x,l,ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>c;
		for(int j=1;j<=x;j++){
			s=s+c;
			sf=c+sf;
		}
	}
	
	l=s.length();
	if(l/2==1){
		l=l/2+1;
	}
	else l=l/2;
	for(long long i=0;i<l;i++){
		if(s[i]==sf[i]) continue;
		else{
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	
} 
