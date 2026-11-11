#include<bits/stdc++.h>
using namespace std;
struct stu{
	long long y,t;
}a[200010];
bool jc(long long x,long long y){
	long long cnt1=0,cnt2=0;
	while(x){
		x/=2;
		cnt1++;
	}
	while(y){
		y/=2;
		cnt2++;
	}
	return cnt1>=cnt2;
}
long long n,m,x,ans,sum;
long long g(long long h){
	long long cnt=0;
	while(h){
		if(h%2==1){
			cnt++;
		}
		h/=2;
	}
	return cnt;
}
bool cmp(const stu &x,const stu &y){
	if(x.t!=y.t) return x.t>y.t;
	return x.y>y.y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&x);
		a[i].y=x;
		a[i].t=g(x);
	}
	sort(a+1,a+n+1,cmp);
	sum=a[1].y;
	for(int i=1;i<=n;i++){
		if(!jc(a[1].y,a[i].y)&&(n-i+1+ans<m)) continue;
		ans++;
		sum&=a[i].y;
		if(ans==m){
			break;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
