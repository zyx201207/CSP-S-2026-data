#include<bits/stdc++.h>
using namespace std;
string S;
int n;
long long a[200005];
char c[200005];
bool flag=true;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		string s(a[i],c[i]);
		S+=s;
	}
	long long len=S.size();
	for(long long i=0;i<len;i++){
		if(!(S[i]=S[S.size()-i-1])) {
			flag=false;
			break;
		}
	}
	if(flag==true) cout<<0;
	
	return 0;
}
