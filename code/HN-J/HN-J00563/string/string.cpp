#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);

	string S,S_hw;
	int S_len;
	int n;
	cin>>n;
	while(n--) {
		int a;
		string c;
		cin>>a>>c;
		for(int i=0; i<a; i++) S+=c;
		S_len+=a;
	}
	for(int i=S_len; i>0; i--) S_hw[abs(i-4)]+=S[i];
	int ans=-1;
	for(int i=0; i<S_len; i++) {
		if(S_hw[i]!=S[i]){
			int x=S[i];
			S[i]=S[abs(i-4)];
			S[abs(i-4)]=x;
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
