#include<bits/stdc++.h>
using namespace std;
struct node{
	int id,g;
}q[200005];
int n,m,a[200005];
bool cmp(node w,node o){
	return w.g>o.g||(w.g==o.g&&w.id>o.id);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int ai=a[i];
		int now=0;
		while(ai){
			if(ai%2==1) now++;
			ai=ai/2;
		}
		q[i].g=now;
		q[i].id=a[i];
	}
	sort(q+1,q+n+1,cmp);
	sort(a+1,a+n+1);
	int ansa=a[n],ansq=q[1].id;
	for(int i=n-1;i>=n-m+1;i--){
		ansa=ansa&a[i];
	}
	for(int i=1;i<=m;i++){
		ansq=ansq&q[i].id;
	}
	cout<<max(ansa,ansq);
	return 0;
}