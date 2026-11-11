#include <bits/stdc++.h>
using namespace std;
int a[500005],d[300005],b[500005];
int n,m,l;
void f(int t){
	int t1=1;
	for(int i=1;i<=n;i++){
		if(t1==0) b[i]=0;
		if(b[i]==t){
			t1=0;
			l=i+1;
		}
	}
	if(t1==1){
		b[l]=t;
		l++;
	}
}
void qing(int t){
	for(int i=1;i<=t;i++){
		b[i]=0;
	}
}
int main(){
	freopen("card","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int n1=n;
	for(int i=1;i<=n;i++){
		l=1;
		qing(n1);
		for(int j=i;j<=n1;j++){
			f(a[j]);
		}
		for(int j=1;j<=n;j++){
			d[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}
	
	return 0;
}
