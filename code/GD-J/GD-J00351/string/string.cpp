#include <bits/stdc++.h>
using namespace std;
const int N = 1e9+5;
int n,ans=0;
char s[N];
bool ishui(char s[N],int l){
	for(int i=0;i<l;i++){
		if(s[i]!=s[l-1-i]){
			return false;
		}
	}
	return true;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int t=0;
	int len=0;
	while(n--){
		int a;
		char c;
		cin>>a>>c;
		for(int i=t;i<t+a;i++){
			s[i]=c;
		}
		t+=a;
		len+=a;
	}
	if(ishui(s,len)){
		cout<<0;return 0;
	}
	while(!ishui(s,len)){
		s[len-1-ans]=s[ans];
		ans++;
	}
	cout<<ans;
	return 0;
}

