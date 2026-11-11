#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.out","w",stdout);
	freopen("string.in","r",stdin);
	
	int n;
	long long ans=0;
	cin>>n;
	while(n--){
		int i;
		char y;
		cin>>i>>y;
		while(i--){
			s+=y;
		}
	}
	unsigned long long j=s.size(),h=s.size();
	int u;
	j/=2;
	for (int i=0;i<j;i++){
		if (s[i]!=s[h-1]){
			ans++;	
		}
		h--;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
