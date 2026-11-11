#include <bits/stdc++.h>
using namespace std;
struct shui{
	int ng;
	int cha;
};
bool cmp(shui x,shui y){
	return x.cha < y.cha;
}
int main(){
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	shui a[500005]={};
	for(int i=1;i<=n;i++){
		 cin>>a[i].ng;
		 a[i].cha=a[i].ng-a[i-1].ng;
	}
	sort(a+1,a+n+1,cmp);
	int b=0,c=0;
	for(int i=1;i<=n;i++){
		 if(i==1)b=b+a[i].cha;
		 else b=b+2*a[i].cha;
		if(b<=m)c++;
	}
	cout<<c;
	return 0;
}
