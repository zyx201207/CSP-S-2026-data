#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a,k=0,g,ss=0;
	char c;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s[k+j]=c;
		}
		k+=a;
	}
	g=k-1;
		for(int i=1;i<=k/2;i++){
			if(s[i]!=s[i+g]){
				ss++;
			}
			g-=2;
		}
	cout<<ss;
	return 0;
}
