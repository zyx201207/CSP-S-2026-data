//X
#include<bits/stdc++.h>
#define int long long
using namespace std;
struct lp{
	int f;
	char s;
}a[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i].f >> a[i].s;
		sum+=a[i].f; 
	}
	int l=1,r=sum,li=1,ri=n,ans=0;
	while(l<r&&li<ri){
		int h=min(a[li].f,a[ri].f);
		if(a[li].s!=a[ri].s)ans+=h;
		l+=h,r-=h;
		if(a[li].f<=a[ri].f){
			li++;
			a[ri].f-=h;
		}
		else{
			ri--;
			a[li].f-=h;
		}
	}
	cout << ans;
	return 0;
} 
//当我们形同陌路，一个字符都吐不出~
//                             ----《松手》 
//我 
