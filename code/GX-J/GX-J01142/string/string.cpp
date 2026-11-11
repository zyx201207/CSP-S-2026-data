#include <bits/stdc++.h>
using namespace std;
long long n,b,c;
struct duan{
	long long x;
	char y;
};
duan a[200010];
long long sum=0,l,r,ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		sum+=a[i].x;
	}
	b=1,c=n;
	while(b<=c){
		long long tmp=min(a[b].x,a[c].x);
		if(a[b].y!=a[c].y){
			ans+=tmp;
		}
		if(a[c].x==a[b].x){
			b++,c--;
		}else if(a[c].x==tmp){
			c--;
			a[b].x-=tmp;
		}else{
			b++;
			a[c].x-=tmp;
		}
	}
	cout<<ans;
    return 0;
}
