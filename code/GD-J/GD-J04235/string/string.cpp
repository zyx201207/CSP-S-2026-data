#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int a[N],n,cnt=0;
	cin>>n;
	char yy;
	for(int i=0;i<n;++i){
		int x; cin>>x;
		char y; cin>>y;
		
		while(x--){
			s+=y;
		}
	}
	n=s.size();
	int sta;
	if(n%2!=0){
		sta=n/2+1;
	}
	else{
		sta=n/2;
	}
	string ts,st;
	for(int i=0;i<n/2;++i){
		ts+=s[i];
	}
	
	cout<<ts<<' ';
	for(int i=sta;i<n;++i){
		st+=s[i];
	}
	int ans=0;
	reverse(st.begin(),st.end());
	for(int i=0;i<ts.size();++i){
		if(ts[i]!=st[i]){
			ans++;
		}
	}
	cout<<st;
}
