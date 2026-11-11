#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
long long n,a[N],ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long l=1,r=n,cnt=a[1],cntt=a[n];
	while(1){
		if(cnt>cntt){
			if(c[l]!=c[r])ans+=cntt;
			cnt-=cntt;
			r--;
			cntt=a[r];
		}else{
			if(c[l]!=c[r])ans+=cnt;
			cntt-=cnt;
			l++;
			cnt=a[l];
		}
		if(l>=r)break;
	}
	cout<<ans;
	return 0;
}
