#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+10;
string s;
struct str{
	long long ch;
	char c;
};
int n,cnt,x;
str a[MAXN];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].ch>>a[i].c;
		x+=a[i].ch;
		for(int j=1;j<=a[i].ch;j++){
			s+=a[i].c;
		}
	}
	if(x%2==0){
		for(int i=0;i<=x/2-1;i++){
			if(s[i]!=s[x-i-1])cnt++;
		}
	}
	else{
		for(int i=0;i<=x/2;i++){
			if(s[i]!=s[x-i-1])cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
