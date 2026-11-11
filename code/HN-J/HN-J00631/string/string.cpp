#include<iostream>
using namespace std;
long long len;
string s=" ";
int ans;
void num(long long x,char y){
	for(long long i=1;i<=x;i++) s+=y;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	char c;
	long long a;
	for(int i=1;i<=n;i++){
		cin>>a;
		cin>>c;
		len+=a;
		num(a,c);
	}
	long long L=1,R=len;
	while(L<=R){
		if(s[L]!=s[R]) ans++;
		L++;
		R--;
	}
	cout<<ans;
	return 0;
}
