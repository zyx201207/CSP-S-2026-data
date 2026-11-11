#include<bits/stdc++.h>
using namespace std;
int n,m,mm,a[500005]={0},g,maxx=0;
int sss(int z){
	int head=z-1,s=1;
	while(m>0){
		if(head==0){
			break;
		}
		if(a[z]-a[head]<=m){
			m=m-(a[z]-a[head]);
			head--;
			s++;
		}else{
			break;
		}
	}
	return s;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>mm;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		m=mm;
		g=sss(i);
		if(g>maxx){
			maxx=g;
		}
	}
	cout<<maxx;
	return 0;
}
