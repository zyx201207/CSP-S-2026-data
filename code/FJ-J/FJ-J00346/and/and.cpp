#include<bits/stdc++.h>
using namespace std;
int f[20005],a,n,b=1,m,mx=-1,num=0,j=0,t[200005][45],v=0,q=0,ans=0;
void s(int w,int x){
	if(num==m){
		num--;
		if(q>mx){
			mx=q;
			q=0;
		}
		return;
	}
	for(j=w;j<=n;j++){
		num++;
		for(int i=1;i<=max(f[j],f[x]);i++){
			if(t[j][i]==1&&t[x][i]==1){
				for(int u=1;u<i;u++){
					b=b*2;
				}
				q+=b;
				b=1;
			}
		}
		s(j+1,j);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		while(a>0){
			t[i][++v]=a%2;
			a=a/2;
		}
		f[i]=v;
		v=0;
	}
	s(2,1);
	cout<<mx;
	return 0;
}
