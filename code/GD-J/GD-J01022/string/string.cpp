#include<bits/stdc++.h>
using namespace std;
long long n,ans;
string s;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x;
		cin>>c;
	 for(int j=1;j<=x;j++){
			s+=c;
		}
	}
	int w=s.size()/2;
	if(s.size()%2)w++;
	w--;
	for(int i=w;i<s.size();i++){
		cout<<s[i]<<' '<<s[w]<<endl;
		if(s[i]!=s[w]){
			ans++;
		}
		w--;
	}
	cout<<ans;
}
