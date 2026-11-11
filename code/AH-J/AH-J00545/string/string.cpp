#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long n,d,ans=0;
int a;
char c;
string s[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a>>c;
		for(int j=1;j<=a;j++){
			s[i]=c;
		}
		d+=a;
	}
	d=d+1;
	int b=d/2+1;
	for(int i=0;i<b;i++){
	if(s[i+1]!=s[i]){
		s[i+1]==s[i];
		ans++;
	}
		if(s[d-1]!=s[i]){
			s[d-1]==s[i];
		ans++;
		d--;}
	}
	cout<<ans<<"\n";
    return 0;
}
