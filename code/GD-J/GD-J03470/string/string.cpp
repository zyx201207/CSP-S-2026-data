#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
long long cnt;
struct node{
	long long a; char c;
}a[N];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].c;
		for(int j=1;j<=a[i].a;j++) s+=a[i].c;
	}
	for(int i=0;i<=((int)s.size()/2);i++) if(s[i]!=s[s.size()-i-1]) cnt++;
	cout<<cnt<<'\n';
	return 0;
} 
