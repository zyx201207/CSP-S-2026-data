#include<bits/stdc++.h>
using namespace std;
#define it long long
it n,a[1000000],pp[1000000],ss[1000000],res[1000000];
char c[1000000];
char s[1000000];
it m,b[1000000],ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	it n;
	for(int i=1;i<=n;i++){
	cin>>a[i];
	cin>>c[i];
	}
	for(int i=1;i<=n;i++){
	pp[i]=pp[i-1]+a[i];
	}
	for(int i=n;i>=1;i--){
		ss[i]=ss[i-1]+a[i];
		}
	it pl=1,pr=0;	
	while(pl<=n){
			it  lsiz=pp[pl],rsiz=ss[pr];
			if(lsiz<rsiz){
			b[++m]=res[pl];
			s[m]=c[pl];
			pl++;
		}else{
		b[++m]=res[pl]-(lsiz-rsiz);
		s[m]=c[pl];
		res[pl]=lsiz-rsiz;
		pr--;
	}
}
for(int i=1;i<=m;i++){
	if(s[i]!=s[m-i+1]){
		ans+=b[i];
	}
}
	cout<<ans;
	return 0;
	}
