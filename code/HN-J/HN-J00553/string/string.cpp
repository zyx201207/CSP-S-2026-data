#include<bits/stdc++.h>
using namespace std;

long long n;
long long s;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;		
	long long longl=0;
	char c;
	bool ans=0;
	for(int i=1;i<=n;i++){
		int a;
		char d;
		cin>>a>>d;
		if(c==d) ans=0;
		else ans=1; 
		c=d;
		for(long long j=1;j<=a;j++){
			s*=10;
			s+=d-'a'+1;
			longl++;
		}
	}
//	cout<<s<<'\n';
	if(ans==0) cout<<0;
	else cout<<(longl/=2);
	return 0;
}
