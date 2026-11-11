#include<bits/stdc++.h>
using namespace std;
string s;
long long n,a,cnt=-1,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	char c;
    	cin>>a>>c;
    	for(int j=1;j<=a;j++){
    		s[++cnt]=c;
		}
	}
	for(int i=0,j=cnt;i<=j;i++,j--){
		if(s[i]!=s[j]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}//Trick||Treat!
