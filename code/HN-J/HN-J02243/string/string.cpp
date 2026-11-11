#include<bits/stdc++.h>
using namespace std;
struct strd{
	char m;
	int am;
}a[1000];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans = 0;
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i].am>>a[i].m;
	}
	for(int i = 1;i <= n;i++){
		for(int j = i;j < a[i].am;j++){
			s[j] = a[i].m; 
		}
	}
	for(int i = 1;i <= n;i++){
		if(a[i].m != a[n + 1 - i].m){
			ans+= a[i].am;
			a[n + 1 - i].m = a[i].m;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
