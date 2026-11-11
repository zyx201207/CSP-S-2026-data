#include<bits/stdc++.h>
using namespace std;
long long n,x,cnt,ans;
char a;
string s;
bool f(string st){
	string st2;
	for(int i=cnt-1;i>=0;i--){
		st2+=st[i];
	}
	if(st2!=st){
		return 0;
	}
	return 1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>a;
		for(int j=1;j<=x;j++){
			s+=a;
			cnt++;
		}
	}
	if(f(s)){
		cout<<0;
		return 0;
	}
	string st;
	for(int i=0;i<cnt/2;i++){
		st+='0';
	}
	if(cnt%2){
		st+='0';
	}
	for(int i=cnt/2-1;i>=0;i--){
		st+=s[i];
	}
	for(int i=cnt/2+cnt%2;i<cnt;i++){
		if(st[i]!=s[i]){
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
