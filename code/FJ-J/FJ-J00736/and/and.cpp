#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],b[200005],s;
int f(int x){
	int t=0;
	while(x){
		t=t*10+x%2;
		x/=2;
	}return t;
}
int h(int x,int y) {
	int w=f(x),r=f(y),t=0;
	while(r) {
		if(w%10==1&&r%10==1)t=t*2+1;
		else t=t*2;
		w/=10;
		r/=10;
	}return t;
}
bool cmp(int x,int y) {
	return x>y;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n,cmp);
	s=a[1];
	for(int i=2;i<=m;i++){
		if(s==a[i])continue;
		else s=h(s,a[i]);
	}cout<<s;
	return 0;
}
