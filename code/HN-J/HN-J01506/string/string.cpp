#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
int n;
const int N=2e5+5;
int a[N];
char c[N];
string s;
ll k;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
		k+=a[i];
		if(i!=1 and c[i]!=c[i-1]){
			f=0;
		}
	}
	if(f){
		cout<<"0";
		return 0;
	}
	ll cnt=0;
	for(int i=0;i<k/2;i++){
		if(s[i]!=s[k-i+1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}

