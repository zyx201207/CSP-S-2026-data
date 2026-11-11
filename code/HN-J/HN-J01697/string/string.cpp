#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10;
long long n,cnt,sum;
double m_;
string s;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	s=' ';
	for(int i=1;i<=n;i++){
		int k;
		string ch;
		cin>>k>>ch;
		while(k--){
			s+=ch;
			cnt++;
		}
	}
	if(cnt%2==0) m_=cnt/2+0.5;
	else m_=(cnt+1)/2;
	for(int i=1;i<m_;i++){
		int r=cnt-i;
		if(s[i]!=s[r]){
			sum++;
		} 
	} 
	cout<<sum;
	return 0;
} 
