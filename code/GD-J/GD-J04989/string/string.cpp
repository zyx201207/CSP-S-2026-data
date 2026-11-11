#include<bits/stdc++.h>//´æE: 
//completed
using namespace std;
typedef long long ll;
int n;
ll total_l=0ll;
struct piece{
	int num;
	char letter;
};
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		total_l+=x;
		while(x--){
			s+=y;
		}
	}
	ll ans=0ll;
	for(int i=0,j=total_l-1;i<j;i++,j--){
		if(s[i]!=s[j]) ans++;
	}
	cout<<ans;
	return 0;
}
