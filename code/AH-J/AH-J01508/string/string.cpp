#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,num,thechar,ans=0;
    string s,linshi1,linshi2;
    cin>>n;
    for(int i=1;i<=n;++i){
    	cin>>num>>thechar;
		s += num*thechar;}
	if(n=1)ans=0;
	else if(n=0)ans=0;

	cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
