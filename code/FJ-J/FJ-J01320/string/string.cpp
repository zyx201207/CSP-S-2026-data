#include <bits/stdc++.h>
using namespace std;
string s;
int n;
long long cnt=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cout.tie(0); cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		long long a; cin>>a;
		char c; cin>>c;
		while(a--) s+=c;
	}
	long long a=s.size();
	if(a%2==0){
		int l=(a/2)-1,r=a/2;
		while(l>=0&&r<=a){
			if(s[l]!=s[r]) cnt++;
			l--; r++;
		}
	}else{
		int l=a/2,r=(a/2)+2;
		while(l>=0&&r<=a){
			if(s[l]!=s[r]) cnt++;
			l--; r++;
		}
	}
	cout<<cnt;
	return 0;
}
