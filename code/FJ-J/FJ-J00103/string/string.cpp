#include<bits/stdc++.h>
using namespace std;
string s;
bool f;
char x,y;
long long n,m,ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >>m>>x;
		if(y==x){
			f=1;
		}else{
			f=0;
		}
		for(long long j=1;j<=m;j++){
			s+=x;
		}
		y=x;
	}
	if(f==1){
		cout <<0;
		return 0;
	}
	long long l=0,r=s.size()-1;
	for(l,r;l<r,r>l;l++,r--){
		if(s[l]!=s[r]){
			ans++;
		}
	}
	cout <<ans;
	return 0;
}
