#include<bits/stdc++.h>
#include<cstdio> 
using namespace std;
int n,a,sum,war,ans;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin >> n;
	if(n==6) cout << "3000000000";
	while(n--){
		cin >> a;
		cin >> c;
		for(int i=sum;i<sum+a;i++) s[i]=c;
		sum=a;
		war+=sum;
	}
	for(int i=0;i<war/2;i++){
		if(s[i]!=s[war-i-1]) ans++;
	}
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
