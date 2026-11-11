#include <bits/stdc++.h>
using namespace std;
int n,a;
char c;
struct zf{
	long long xia;
	char xing;
};
const long long MAXN=2*1e5+5;
zf v[MAXN];
long long ans,sum=0;
int tong[26];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	ans=n/2;
	for(int i=1;i<=n;i++){
		cin>>v[i].xia>>v[i].xing;
		tong[v[i].xing-'a']++;
		sum+=v[i].xia;
	}
	int time=0;
	for(int i=0;i<26;i++){
		if(tong[i]!=0) time++;
		if(time>1) break;
	}
	if(time==1){
		cout<<0<<endl;
		return 0;
	}
	ans=sum/2;
	cout<<ans<<endl;
	return 0;
}
