#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct num{
	LL x,y;
}a[400010];
LL xx(LL t){
	LL cnt=0;
	while(t){
		if((t&1)==1){
			cnt++;
		}
		t/=2;
	}
	return cnt;
}
bool cmp(num x,num y){
	if(x.y!=y.y) return x.y>y.y;
	return x.x>y.x;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	LL n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
		a[i].y=xx(a[i].x);
	}
	sort(a+1,a+n+1,cmp);
	if(m==1){
		cout<<a[1].x;
	}else if(m==n){
		LL sum=a[1].x;
		for(int i=2;i<=n;i++){
			sum&=a[i].x;
		}
		cout<<sum;
	}else{
		LL sum=a[1].x,t=1;
		for(int i=2;i<=n;i++){
			//if(xx(sum)>xx(a[i].x)&&n-i+1>=m-t) continue;
			t++;
			sum&=a[i].x;
			if(t==m) break;
		}
		cout<<sum;
	}
	return 0;
}
