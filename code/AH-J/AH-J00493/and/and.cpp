#include<bits/stdc++.h>
using namespace std;
int n,m,ma;
struct ZmjjKK{
	int num,len;
	string s;
}a[200005];
bool cmp(ZmjjKK x,ZmjjKK y){
	if(x.len!=y.len)return x.len>y.len;
	return x.s>y.s;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].num;
		int t=a[i].num;
		while(t){
			a[i].s=char(t%2+'0')+a[i].s;
			a[i].len++;
			t/=2;
		}
	}
	sort(a+1,a+n+1,cmp);
	ma=a[1].num;
	for(int i=2;i<=m;i++){
		ma&=a[i].num;
	}
	cout<<ma;
	return 0;
}
