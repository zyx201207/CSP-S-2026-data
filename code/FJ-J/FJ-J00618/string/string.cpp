#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[1000001];
string s;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>s;
	}
	if(n==1){
		cout<<0;
		return 0;
	}else if(n==2){
		if(s[0]==s[1]){
			cout<<0;
			return 0;
		}else{
			if(a[0]<=a[1]){
				cout<<a[0];
				return 0;
			}else if(a[0]>a[1]){
				cout<<a[1];
				return 0;
			}
		}
	}	
	cout<<a[n];
	return 0;
}

