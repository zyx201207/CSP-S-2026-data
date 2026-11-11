#include<bits/stdc++.h>
using namespace std;
string s;
char c;
int n,p;
long long z=1;
long long ans=0;
int main()
{
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p>>c;
		if(z==1){
			for(int i=1;i<=p;i++){
				s[i]=c;
			}
			z=p+1;
		}else{
			for(int i=z;i<=p+z-1;i++){
				s[i]=c;
			}
			z+=p;
		}
	}
	z-=1;
	
	bool be;
	if(z%2==0) be=true;
	else be=false;
	if(be){
		for(int i=1;i<=z/2;i++){
			if(s[i]!=s[z-i+1]) ans++;
		}
	}else{
		for(int i=1;i<=(z-1)/2;i++){
			if(s[i]!=s[z-i+1]) ans++;
		}
	}
	cout<<ans;
	return 0;
}
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout); 

