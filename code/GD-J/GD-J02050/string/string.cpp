#include <bits/stdc++.h>
using namespace std;
unsigned long long n,a;
string s,c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
	    cin>>a>>c;
	    for(int j=1;j<=a;j++){
	    	s+=c;
		}
    }
    long long m=(s.length()>>2)+1,cnt=0;
    for(unsigned long long i=m;i<=s.length()-1;i++){
    	if(s[i]!=s[i-m]) cnt++;
	}
	cout<<cnt/2+cnt%2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
