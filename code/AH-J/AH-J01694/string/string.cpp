#include<bits/stdc++.h>
using namespace std;
string s;
const int N=200005;
int a;
char c;
long long ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		s.append(a,c);
	}	
	for(long long i=0,j=s.length()-1;i<j;i++,j--)
	{
		if(s[i]!=s[j]){
			s[i]=s[j];
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
