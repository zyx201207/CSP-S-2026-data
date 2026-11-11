#include<bits/stdc++.h>
using namespace std;
int n;
long long ret;
vector<char>s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	int sl;
	char zf;
	for(int i=1;i<=n;i++){
		cin>>sl>>zf;
		for(int i=1;i<=sl;i++)s.push_back(zf);
	}
	long long l=0,len=s.size();
	for(long long i=len/2;i>=0;i--){
		if(s[i]!=s[l])ret++;
		l++;
	}
	cout<<ret<<"\n";
	return 0;
}

