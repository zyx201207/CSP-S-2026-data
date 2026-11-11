#include<bits/stdc++.h>
using namespace std;
long long s,as,d=1e18,s1;
struct node{
	long long c,num;
}a[500005];
bool cmp(node x,node y){
	return x.c<y.c;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].num;
		s+=a[i].num;
	}
	long long x=s/n;
	for(int i=1;i<=n;i++){
		if(d>=abs(a[i].num-x))
			d=abs(a[i].num-x);
	}
	for(int i=1;i<=n;i++)
		a[i].c=abs(a[i].num-d);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		s1+=a[i].c;
		if(s1>m) break; 
		as++;
	}
	cout<<as;
	return 0;
} 
