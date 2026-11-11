//GZ-J00298 遵义四中 秦近东	 
#include <bits/stdc++.h>
using namespace std;
void po(string s){
	long long j=0,ll=s.size();
	for(int i=0;i<ll/2;i++){
		if(s[i]!=s[ll-1-i]) j++;
	}cout<<j;
}
long long n,l,ll;
char a;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>l>>a;
    	while(l--){
    		s+=a;
		}
	}
	po(s);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

