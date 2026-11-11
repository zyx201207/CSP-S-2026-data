#include<bits/stdc++.h>
using namespace std;
struct sz{
	long long sjz;
	int ejzys;
}a[200005];
int zh(long long n){
	int s=0;
	while(n>0){
		if(n%2==1) s++;
		n/=2;
	}
	return s;
}
bool cmp(sz p,sz q){
	if(p.ejzys!=q.ejzys)return p.ejzys>q.ejzys;
	return p.sjz>q.sjz;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i].sjz;
	}
	for(int i=0;i<n;i++){
		a[i].ejzys=zh(a[i].sjz);
	}
	sort(a,a+n,cmp);
	int k=a[0].sjz;
	for(int i=1;i<m;i++){
		k=k&a[i].sjz;
	}
	cout<<k;
	return 0;
}
