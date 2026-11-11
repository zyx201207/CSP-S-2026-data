#include<bits/stdc++.h>
using namespace std;
struct S{
	long long a,b=0,c;
}s[500010];
bool cmp(S x, S y){
	return x.b<y.b;
}
bool cmp1(S x,S y){
	return x.a>y.a;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i].a;
	}
	sort(s+1,s+1+n,cmp1);
	for(int i=1;i<n;i++){
		s[i].c=s[i].a-s[i+1].a;
	}
	bool f=1;
	for(int i=1;i<n-1;i++){
		if(s[i].c!=s[i+1].c) f=0;
	}
	if(f){
		int k=s[1].c;
		int p=1;
		while(m>=p*k){
			m-=p*k;
			p++;
		}
		cout<<p;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			s[i].b+=abs(s[i].a-s[j].a);		
			s[j].b+=abs(s[i].a-s[j].a);
		}
	}
	int mn=INT_MAX;
	int t;
	for(int i=1;i<=n;i++){
		if(s[i].b<mn){
			mn=s[i].b;
			t=i;
		}
	}
	for(int i=1;i<=n;i++){
		 s[i].b=abs(s[i].a-s[t].a);
	}
	sort(s+1,s+1+n,cmp);
	int j=1;
	while(m>=s[j].b){
		m-=s[j].b;
		j++;
	}
	cout<<j-1;
	return 0;
}
