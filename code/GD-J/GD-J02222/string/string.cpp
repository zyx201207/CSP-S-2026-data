#include<bits/stdc++.h>
#define ll long long
using namespace std;

string r[200005];
int c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s="";
	cin>> n;
	ll cnt =0;
	for(int i=0;i<n;i++){
		cin >> c[i];
		cin >> r[i];
		if(i>(n-1)*0.5){
			if(c[i]=c[n-i-1] && r[i]!=r[n-i-1]){	
				cnt+=c[i];
				for(int j=0;j<c[i];j++){
					s += r[n-i-1];
				}
				continue;
			}
		}
		for(int j=0;j<c[i];j++){
			s += r[i];
		}
	}
	/*for(int i=0;i<a;i++){
		cout << pass[i] << endl;
	}*/
	for(ll i=0;i<s.size()/2;i++){
		cnt+=s[i]!=s[s.size()-i-1];
		//cout << s[i] << " " << s[s.size()-i-1] << endl;
	}
	cout << cnt;
	return 0;
}
