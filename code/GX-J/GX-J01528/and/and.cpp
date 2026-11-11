#include<bits/stdc++.h>
#define MAXN 1000000
using namespace std;
struct number{
	int sjz;
	string ejz;
}a[MAXN];
string zh(int x){
	string s="01";
	string ans="";
	while(x>0){
		ans=ans+s[x%2];
		x/=2;
	}
	return ans;
}
bool cmp(number x,number y){
	if(x.ejz.size()!=y.ejz.size()) return x.sjz>y.sjz;
	return x.ejz>y.ejz;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i].sjz;
		a[i].ejz=zh(a[i].sjz);
	}
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=m;i++){
		a[i].sjz=(a[i].sjz&a[i-1].sjz);
	}
	cout<<a[m].sjz;
    return 0;
}
