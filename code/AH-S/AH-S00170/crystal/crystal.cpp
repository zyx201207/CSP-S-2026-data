#include<bits/stdc++.h>
using namespace std;
void run(long long a,long long b){
	long long i,f,d;
	for(i=1;f<=b;i++){
		f=i*(i+1)/2*a;
		d=i;
	}
	cout<<d-1;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,cnt,yn=0,y;
    scanf("%lld%lld",&n,&m);
	long long a[n+1],s[n+1];
    for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=2;i<=n;i++)
		s[i]=a[i]-a[i-1];
	bool flag=true;
	for(int i=3;i<=n;i++){
		if(s[i]!=s[i-1]) flag=false;
	}
	if(flag) {
		run(s[3],m);
		return 0;
	}
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
		cnt=0;
        for(int j=i-1;j>=1;j--){
			cnt=cnt+a[i]-a[j];
			if(cnt>=m){
				y=i-j+1;
				yn=max(yn,y);
				break;
			}
		}
	}
	cout<<yn;
    return 0;
}
