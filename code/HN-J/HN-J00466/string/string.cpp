#include<bits/stdc++.h>
using namespace std;
vector<char> s;
long long ans,n,y;
char x;
bool hw(long long l,long long t){
	while(l!=t){
		if(s[l]!=s[t])
			return false;
		l++;
		t--;
	}
	return true;
}
long long cs(int q){
	long long L=0,R=s.size()-1;
	while(hw(L,R)==false){
		if (s[L]!=s[R]){
			s[R]=s[L];
			ans++;
			L++;
			R--;
		}
		if(L==R)	break;
	}
	return ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>y>>x;
		for(long long j=0;j<y;j++)
			s.push_back(x);
	}
	cout<<cs(1);
	return 0;
}
