#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	string s;
	for(int i=1;i<=n;i++){
		int a;
		string c;
		cin >> a >> c;
		for(int j=1;j<a;j++){
			c+=c[0];
		}
		s+=c;
	}
	long long cnt=0;
	long long sl=s.size();
	for(int i=0;i<sl;i++){
		long long j;
		if(sl%2==0) j=sl-i;
		else j=sl-i-1;
		if(i>=j) break;
		if(s[i]!=s[j]){
			cnt++;
		}
	}
		
	
	
		
	cout << cnt;




	return 0;
}
