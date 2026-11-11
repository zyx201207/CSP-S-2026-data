#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<ll> a;
ll m;
int main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	int i=0;
	string text;
	gets(text);
	istringstream iss(text);
	int num;
	while(iss>>num) {
	a[i]=num;
	i++;
	}
	map<int> repeat;
	for(int i=0;i<=m;i++){
		repeat[a[i]]++;
		}
	int m=repeat[a[0]];
	for(c:repeat[]){
		if(c>m) m=c;
		}
	}
	

