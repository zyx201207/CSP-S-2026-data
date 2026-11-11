#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct h{
	long long a,c;string b;
}s[N];
bool cmp(h w,h t){
	if(w.c!=t.c)return w.c>t.c;
	else return w.a>t.a;
}
int main(){
	int n,m,ans=0;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i].a;
		long long x=s[i].a;
		while(x){
			s[i].b=char(x%2+'0')+s[i].b;
			if(char(x%2+'0')=='1')s[i].c+=1;
			x>>=1;
		}
	}
	
	sort(s+1,s+n+1,cmp);
	ans=s[1].a;
	for(int i=2;i<=m;i++){
		ans=ans&s[i].a;
	}
	cout<<ans;
	return 0;
}
