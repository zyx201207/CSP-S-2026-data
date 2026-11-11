//GZ-J00630 张庭赫 贵阳中天中学 
#include<bits/stdc++.h>
using namespace std;
string s;
int cnt,ans;

int check(int a){
	int x;
	if(a%2==0) x=a/2;
	else x=(a+1)/2;
	return x;
}
int main(){
	#define int long long
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin>>n;
	while(n--){
		int a;
		string b;
		cin>>a>>b;
		cnt+=a;
		for(int i=1;i<=a;i++){
			s+=b;
		}
	}
	for(int i=0;i<check(cnt);i++){
		if(s[i]!=s[cnt-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
