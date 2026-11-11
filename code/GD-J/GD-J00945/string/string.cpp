#include<bits/stdc++.h>
#include<string>
using namespace std;
long long n;
long long s;
string a = {};
string r = {};
string d = {};
long long sum = 0,ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> s >> a;
		sum+=s;
		for(int j=0;j<s;j++){
			r+=a;
		}
	}
	for(int i=r.size()-1;i>=0;i--){
		d+=r[i];
	}
	if(d==r){
		cout << 0;
		return 0;
	}
	else{
		for(int i=0;i<sum;i++){
			if(d[i]!=r[i]){
				ans++; 
			}
		}
	}
	cout << ans/2;
	return 0;
}
