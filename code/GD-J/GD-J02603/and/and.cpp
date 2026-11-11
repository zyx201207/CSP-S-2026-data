#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],s,ss,sss;

bool ccmp(int x,int y){
	return x>y;
}
bool cmmp(int x,int y){
	int e=0,f=0;
	while(x){
		e+=x%2;
		x/=2;
	}
	while(y){
		f+=y%2;
		y/=2;
	}
	if(e!=f)return e>f;
	else return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,ccmp);
	ss=a[1];
	for(int i=2;i<=m;i++){
		ss&=a[i];
	}
	sort(a+1,a+n+1,cmmp);
	sss=a[1];
	for(int i=2;i<=m;i++){
		sss&=a[i];
	}
	cout<<max(max(s,ss),sss);
	return 0;
} 
