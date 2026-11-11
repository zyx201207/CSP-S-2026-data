#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll m;
int n;
int a[N];
int cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	int maxx=1;
	for(int i=1;i<=n;i++){
		ll cnt=0;bool flag=1;
		for(int j=i-1;j>=1;j--){
			cnt+=a[i]-a[j];
			if(cnt>m){
				maxx=max(maxx,i-j);
				flag=0;
				break;
			}else if(cnt==m){
				maxx=max(maxx,i-j+1);
				flag=0;
				break;
			}
		}
		if(flag) maxx=max(maxx,i);
	}
	printf("%d",maxx);
	return 0;
} 
