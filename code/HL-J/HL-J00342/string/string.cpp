#include <bits/stdc++.h>
using namespace std;
const int N=100000;
long long n,a,last=0,sum=0;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	while(n--){
		cin>>a>>c;
		for(int i=last;i<last+a;i++){
			s[i]=c;
		}
		last+=a;
	}
	string t=s;
	reverse(s.begin(),s.end());
	for(int i=0;i<last;i++){
		if(t[i]!=s[i]){
			sum++;
		}
	}
	cout<<(sum+1)/2;
	return 0;
} 
