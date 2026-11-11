#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ans;
struct o{
	ll id,zhi;
}a[1000010];
struct oq{
	ll id1,id2,czhi;
}b[1000009];
bool cmp1(o x,o y){
	return x.zhi>y.zhi;
}
bool cmp2(oq x,oq y){
	return x.czhi<y.czhi;
}

int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].zhi;
		a[i].id=i;
	}
	sort(a+1,a+n,cmp1);
	for(int i=1;i<n;i++){
		b[i].czhi=a[i].zhi-a[i+1].zhi;
		b[i].id1=i;
		b[i].id2=i+1;
	}
	sort(b+1,b+n,cmp2);
	cout<<a[b[1].id1].zhi<<' '<<a[b[1].id2].zhi;
	ans=a[b[1].id1].zhi&a[b[1].id2].zhi;
	for(int i=2,j=1;i<m;i++){
		if(j==1){
			ans=ans&a[b[i].id1].zhi;
			j=2;
		}else{
			ans&=a[b[i].id2].zhi;
			j=1;
		}
	}
	cout<<ans;
	//»Ö¸´freopen 
	
	return 0;
} 
