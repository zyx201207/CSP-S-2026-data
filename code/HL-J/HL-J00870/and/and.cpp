#include <bits/stdc++.h>
using namespace std;
const int N=2e5+100;
int n,m;
struct H{
	int v;
	int len;
	int s1;
}a[N];
void changed(int i){
	int h=a[i].v,sum=0,flag=0;
	while(h){
		if(h%2==1)sum++;
		flag++;
		h/=2;
	}a[i].len=flag;
	a[i].s1=sum;
}bool cmp(H a,H b){
	if(a.s1!=b.s1)return a.s1>b.s1;
	return a.len>b.len;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].v;
		changed(i);
	}sort(a+1,a+n+1,cmp);
	int d=a[1].v;
	for(int i=2;i<=m;i++){
		d&=a[i].v;
	}cout<<d;
	return 0;
}