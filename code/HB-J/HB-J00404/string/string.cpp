#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string s,ss;
long long ans=0;
struct st{
	long long cnt;
	char t;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	bool ff=0;
	
	for(int i=1;i<=n;i++){
		cin>>a[i].cnt>>a[i].t;
		if(a[i].cnt>=100000000)a[i].cnt=1;
		for(int j=1;j<=a[i].cnt;j++)ss+=a[i].t;
	}
	char s=a[1].t;
	for(int i=1;i<=n;i++){
		if(s!=a[i].t)ff=1;
		for(int j=1;j<=a[i].cnt;j++)ss+=a[i].t;
	}
	if(ff==0){
		cout<<0;return 0;
	}
	int x=0,y=n-1;
	while(x<=y){
		ss[x]=s[x];
		ss[y]=s[x];
		x++;y--;
	}
	for(int i=1;i<=n;i++){
		if(s[i]!=ss[i])ans++;
	}
	cout<<ans;
	/*
	6
 1000000000 a
 1000000000 a
 1000000000 a
 1000000000 b
 1000000000 b
 1000000000 b
	*/
	return 0;
}
