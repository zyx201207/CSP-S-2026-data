#include <iostream>
using namespace std;
int n,m,sum=0,ans=0;
char a;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>> m >> a;
		sum+=m;
		while(m--) s+=a;
	}
	//cout<<s[sum-1];
	for(int i=0;i<sum/2;i++){
		if(s[i] != s[sum-i-1]) ans++;
	}
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);//*/
}
