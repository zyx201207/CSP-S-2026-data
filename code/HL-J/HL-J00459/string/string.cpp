#include<bits/stdc++.h>
using namespace std;
string s;
int n;
long long l,sum;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	long long a;
    	char c;
    	cin>>a>>c;
    	for(int j=0;j<a;j++){
    		s+=c;
		}
		l+=a;
	}
	for(int i=0;i<l/2;i++){
		if(s[i]!=s[l-1]) sum++;
	}
	cout<<sum;
    return 0;
}
