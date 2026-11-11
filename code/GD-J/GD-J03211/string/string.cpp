#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+5;
long long n,cnt=1,cntt;
long long a[N],sum;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		cin>>a[i]>>c[i];
	}
	while(cnt+cntt<n){//前后不重合 则执行 
	    //判断字母是否相等
		if(c[cnt]!=c[n-cntt]){ //不相等 
			if(a[cnt]>=a[n-cntt]){
				sum+=a[n-cntt];
				a[cnt]-=a[n-cntt];
				a[n-cntt]=0;
				++cntt;
				if(a[cnt]==0){
					++cnt;
				}
			}
			else{ 
				sum+=a[cnt];
				a[n-cntt]-=a[cnt];
				a[cnt]=0;
				++cnt;
			}
		}
		else{//相等
			if(a[cnt]>=a[n-cntt]){
				a[cnt]-=a[n-cntt];
				a[n-cntt]=0;
				++cntt;
				if(a[cnt]==0){
					++cnt;
				}
			}
			else{
				a[n-cntt]-=a[cnt];
				a[cnt]=0;
				++cnt;
			}
		}
	}
	cout<<sum;
	return 0;
}
//6
//1000000000 a
//1000000000 a
//1000000000 a
//1000000000 b
//1000000000 b
//1000000000 b

