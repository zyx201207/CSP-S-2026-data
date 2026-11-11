#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
int a1[30],a[200010];
string s;
char c[200010];
bool f;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int x;
	for(int i = 0;i < n;i++){
		cin>>a[i]>>c[i];
		a1[c[i]-'0']++;
	}
	x = a[c[0]-'0'];
	for(int i = 0;i < n;i++){
		if(x == a[c[i]-'0']){
			f = true;
			break;
		}else{
			f = false;
		}
	}
	if(f == false){
		for(int i = 0;i < n;i++){
			for(int j = 1;j <= a[i];j++){
				s+=c[i];
			}
		}
		long long l = 0,r = s.length()-1;
		while(l < r){
			if(s[l] != s[r]) ans++;
			l++;
			r--;
		}
		cout<<ans;
	}else{
		for(int i = 0;i < n;i++){
			if(c[i] != c[0]) ans+=a[i];
		}
		cout<<ans;
	}
	return 0;
}
