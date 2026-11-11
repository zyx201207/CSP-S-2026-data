#include<iostream>
using namespace std;
typedef long long ll;
ll n,a,lens,cnt;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a>>c;
		for(ll i=1;i<=a;i++) s+=c;
	}
	lens=s.size();
	for(ll i=0;i<lens/2;i++){
		if(s[i]!=s[lens-i-1]) cnt++;
	}
	cout<<cnt;
    return 0;
}
