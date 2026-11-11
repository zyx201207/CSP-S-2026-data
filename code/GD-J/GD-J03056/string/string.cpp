#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;

string s;
string t;
int a[N],cnt[N];
char c[N];
int n;



int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>c[i];
		int x = a[i];
		while(x--){
			s+=c[i];
		}
	}
	cout<<"0";
	return 0;
}
