#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int a[MAXN];
long long b;
string s;
int main(){
	//freopen("string1.in","r",stdin);
	//freopen("string1.out","w",stdout);
	
    cin>>b;
    int cnt=0;
    
    for(int i=1;i<=b;i++){
    	int n;
    	cin>>n;
    	char c;
    	cin>>c;
    	for(int j=1;j<=n;j++){
    		cnt++;
    		s[cnt]=c;
		}
	}
	int ans=0;
	for(int i=1;i<=ci++){
		if(s[i]!=s[c+i-1])
		ans++;
	}
	cout<<ans;
    return 0;
}
