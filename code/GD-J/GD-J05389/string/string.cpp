#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
struct node{
	int k;
	char c;
};
int n,sum,ans;
node a[2*N];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].k>>a[i].c;
		for(int j=1;j<=a[i].k;j++)
			s+=a[i].c;
	}
	int l=s.length();
	for(int i=0;i<l/2+(l%2)+1;i++){
		if(s[i]!=s[l-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}
