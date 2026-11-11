#include <bits/stdc++.h>
using namespace std;
#define int long long
string c,s,C,S;
int sum,cnt;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c >> s >> C >> S;
	if(c==C) cout << 1;
	else cout << 0;
	if(c!=C) cout << 0;
	else{
		for(int i=0;i<s.size();i++){
			if(s[i]>='0'&&s[i]<='9') sum=sum*10+(s[i]-'0');
		}
		for(int i=0;i<S.size();i++){
			if(S[i]>='0'&&S[i]<='9') cnt=cnt*10+(S[i]-'0');
		}
		if(sum==cnt) cout<< 1;
		else cout<< 0;
	}
	if (c!=C || sum!=cnt) cout << 0;
	else{
		int r=s.size(),x=S.size();
		if(s[r-1]<='C' && S[x-1]<='C') cout << 1;
		else if(s[r-1]>='D' && S[x-1]>='D') cout << 1;
		else cout << 0;
	}
	if(c!=C || sum!=cnt) cout << 0;
	else{
		int r=s.size(),x=S.size();
		if(s[r-1]=='D' && S[x-1]=='F') cout << 1;
		else if(s[r-1]=='F' && S[x-1]=='D') cout << 1;
		else if(s[r-1]=='A' && S[x-1]=='B') cout << 1;
		else if(s[r-1]=='B' && S[x-1]=='A') cout << 1;
		else if(s[r-1]=='B' && S[x-1]=='C') cout << 1;
		else if(s[r-1]=='C' && S[x-1]=='B') cout << 1;
		else cout << 0;
	}
	return 0;
}
