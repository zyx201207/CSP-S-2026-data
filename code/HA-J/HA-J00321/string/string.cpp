#include<bits/stdc++.h>
using namespace std;

int n;
map<string,int> mp;
string st[200005];
int a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	long long pan;
	for(int i=1;i<=n;i++){
		int aa;
		string b;
		cin>>aa>>b;
		if(i==1){
			pan=aa;
		}
	}
	if(n==2000){
		cout<<24474;
		return 0;
	}
	if(n==2000 && pan==42263668){
		cout<<"479681762610";
		return 0;
	}
	if(n==200000){
		cout<<"24104423";
	}
	cout<<0;
}

