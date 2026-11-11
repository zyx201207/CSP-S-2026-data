#include<bits/stdc++.h>
using namespace std;
int n,m,aa[500005],ans=-1,ii=2,m1,ans1=0,c,c1,c2,k;
int ab(int a,int b){
	if(a>b) return a-b;
	else return b-a;
}
bool cmp(int x,int y){
	c1=ab(x,ii);
	c2=ab(y,ii);
	return c1<c2;
}
int f(){
	sort(aa,aa+n,cmp);
	for(int i=0;i<n;i++){
		c=ab(aa[i],ii);
		//cout<<aa[i]<<' '<<c<<endl;
		if(ii>=aa[i]&&c<=m1){
			m1-=c;
			ans1++;
		}
	}
	return ans1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	    cin>>aa[i];
	for(ii=-1000;ii<=1000;ii++){
		m1=m,ans1=0,k=f();
	    ans=max(ans,k);
	}
	cout<<ans;
	return 0;
}
