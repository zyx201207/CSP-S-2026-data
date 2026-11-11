#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200100];
bool cp(int x,int y){
	return x>y;
}
long long zf(int x,int y){
	long long s1,s2,la=0,o=0;
	while(x&&y){
		s1=x%2,s2=y%2;
		x/=2,y/=2;
		if(s1&&s2) la+=pow(2,o);
		o++;
	}
	return la;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cp);
	for(int i=2;i<=m;i++){
		a[i]=zf(a[i-1],a[i]);
	}
	cout<<a[m];
	return 0;
}
