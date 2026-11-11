#include<bits/stdc++.h>
using namespace std;
struct cuang{
	long long len;
	char zf;
}a[200005];
long long res=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].len>>a[i].zf;
	}
	int lt=0,rt=n-1;
	while(n>=1){
		if(a[lt].len>a[rt].len){
			if(a[lt].zf!=a[rt].zf){
				res+=min(a[lt].len,a[rt].len);
			}
			a[lt].len-=a[rt--].len;
			n--;
		}
		else{
			if(a[rt].zf!=a[lt].zf){
				res+=min(a[rt].len,a[lt].len);
			}
			a[rt].len-=a[lt++].len;
			n--;
		}
	}
	cout<<res;
	return 0;
}
