#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int t=1;
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')t=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return t*x;
}
int n;
vector<char> s;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    n=read();
    int cnt=-1;
    for(int i=1;i<=n;i++){
		int a;
		char c;
		a=read();
		c=getchar();
		for(int j=1;j<=a;j++){
			s.push_back(c);
			++cnt;
		}
	}
	int ans=0;
	if(cnt%2!=0){
		int d=(cnt-1)/2;
		for(int i=0;i<=d;i++){
			int j=cnt-i;
			if(s[i]!=s[j])ans++;
		}
	}else{
		int d=cnt/2;
		for(int i=0;i<d;i++){
			int j=cnt-i;
			if(s[i]!=s[j])ans++;
		}
	}
	cout<<ans;
    return 0;
}
