#include<bits/stdc++.h>
using namespace std;
long long n,ans=0;
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		int x;string y;
		cin >> x >> y;
		while(x){
			s+=y;
			x--;
		}
	}
	long long i=0,j=s.length()-1;
	while(i<j){
		if(s[i]!=s[j]){
			ans++;
		}
//		cout << s[i] << " " << s[j] << endl;
		i++;
		j--;
	} 
	cout << ans;
	return 0;
}

