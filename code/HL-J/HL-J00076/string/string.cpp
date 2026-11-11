#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,count=0,s=0,ans=0;
	cin >> n;
	string S;
	for(int i=0;i<n;i++){
		int a;
		string c;
		cin >> a >> S[count];
		for(int j=0;j<a;j++){
			count++;
			S[count]=S[count-1];
		}
	}
	s=count/2;
	for(int i=0;i<s;i++){
		if(S[i]!=S[count]){
			ans++;
			count--;
		}
	}
	cout << ans;
    return 0;
}
