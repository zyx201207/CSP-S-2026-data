#include<bits/stdc++.h>
using namespace std;
long long n,a,cnt;
char c;
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		while(a--){
			s=s+c;
		}
	}
	//cout<<s<<' '<<s.size()<<endl;
	for(int i=0;i<s.size()/2;i++){
		//cout<<s[i]<<'-'<<s[s.size()-i-1]<<endl;
		if(s[i]!=s[s.size()-i-1])cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}


