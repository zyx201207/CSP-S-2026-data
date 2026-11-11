#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
struct num{
	int a,tot=0,len=0;
}a[200010];
bool cmp(num a,num b){
	if(a.tot==b.tot){
		return a.a>b.a;
	}
	return a.tot>b.tot;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].a);
		int tmp=a[i].a;
		while(tmp>0){
			if(tmp%2==1){
				a[i].tot++;
			}
			tmp/=2;
		}
	}
	sort(a+1,a+1+n,cmp);
	cout<<a[1].a;
	return 0;
}

