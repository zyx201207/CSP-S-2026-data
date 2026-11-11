#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans=0,cha[500005],l;
void cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans+=a[i];
	}
	int o=ans/n;
	for(int i=1;i<=n;i++){
		if(a[i]<o){
			cha[i]=o-a[i];	
		}
	}
	int minn=cha[i];
	sort(cha+1,cha+n+1,cmp);
	for(int i=1;i<=n;i++){
		m-=cha[i];
		if(m==0)break;
	}
	return 0;
}
