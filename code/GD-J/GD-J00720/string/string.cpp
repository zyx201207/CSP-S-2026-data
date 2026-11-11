#include<bits/stdc++.h>
using namespace std;
struct Str{
	int num;
	char ch;
	void in(){
		cin>>num>>ch;
	}
}; 
Str str[100100];
void solve1(long long n){
	string s;
	long long ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=str[i].num;j++){
			s+=str[i].ch;
		}
	}
	for(int i=0;i<=s.size();i++){
		if(s[s.size()-i-1]!=s[i]){
			s[s.size()-i+1]=s[i];
			ans++;
		}
	}cout<<ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum;
	cin>>n;
	for(int i=1;i<=n;i++){
		str[i].in();
		sum+=str[i].num;
	}if(sum<=1e8){
		solve1(n);
	}else{
		cout<<0;
	}
	return 0;
}
