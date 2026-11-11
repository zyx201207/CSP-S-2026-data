#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<char,ll>q;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	while(n>0){
		n--;
		char A;
		ll B;
		cin>>B>>A;
		q.insert({A,B});
		for(int j=0;j<B;j++) s+=A;
	}
	ll L=s.size();
	ll cnt=0;
	for(ll i=0;i<=L/2;i++){
		if(s[i]!=s[L-i-1]){
			char h=s[i],r=s[L-i-1];
			if(q[h]>q[r]){
				cnt++;
				q[h]++;
				q[r]--;
				s[L-i-1]=h;
			}
			else{
				cnt++;
				q[h]--;
				q[r]++;
				s[i]=r;
			}
		}
	}
	cout<<cnt;
	return 0;
}
