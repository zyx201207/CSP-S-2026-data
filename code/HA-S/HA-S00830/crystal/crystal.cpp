#include<bits/stdc++.h>
using namespace std;
long long n,m,d,ans,q;
struct p{
	long long ceng;
	long long xian;
}a[500005];
bool cmp(p a,p b){
	return a.ceng>b.ceng;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	d=m;
	for(int i=1;i<=n;i++){
		cin >> a[i].ceng;
	}
	sort(a+1,a+1+n,cmp);
	a[1].xian=a[1].ceng;
	for(int i=1;i<=n-1;i++){
		if(a[i].xian-a[i-1].ceng<=d){
			q++;
			d-=a[i].xian-a[i-1].ceng;
			a[i-1].xian=a[i].ceng;
			if(q>ans){
				ans=q;
			}
		}
		else{
			q=0;
			d=m;
			a[i].xian=a[i].ceng;
			if(a[i].xian-a[i-1].ceng<=d){
				q++;
				d-=(a[i].xian-a[i-1].ceng);
				a[i-1].xian=a[i].xian;
				if(q>ans){
					ans=q;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
