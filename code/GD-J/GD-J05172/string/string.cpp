#include<bits/stdc++.h>
using namespace std;
int n,cnt,ans=0;
string s;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int op;
		char c;
		cnt +=op;
		cin>>op>>c;
		for(int i=1;i<=op;i++) s +=c;
	}
	int l=0;
	cnt--;
	while(l<=cnt){
		if(s[l]!=s[cnt]) ans++;
		l++,cnt--;
	}
	cout<<ans;
	return 0;
}
