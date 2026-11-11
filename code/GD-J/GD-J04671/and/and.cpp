#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005],c[500005];
int n,m,v=1,t;
void ans(int r,int s){
	if(s>m){
		t=c[1];
		for(int i=2;i<=m;i++){
			t=t & c[i];
		}
		b[v++]=t;
		return ;
	}
	for(int i=r;i<=n;i++){
		c[s]=a[i];
		ans(i+1,s+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	ans(1,1);	
	
	int max=-1;
	for(int i=1;i<v;i++){
		if(max<b[i]) max=b[i];
	}
	cout<<max;
	return 0;
	
}
