#include<iostream>
#define int long long 
using namespace std;
int a[200005],s[200005];
char c[200005];
int n,l,sum,mid,rpos,ls,rs,ans,lnow,rnow,lf;
signed main(){
	freopen("string.in","r",stdin);freopen("string.out","w",stdout);
	cin>>n;
	for(int i =1;i<=n;i++){
		cin>>a[i]>>c[i];
		s[i] = s[i-1]+a[i];
		l += a[i];
	}
	for(int i =1;i<=n;i++){
		if(s[i]>=l/2){
			mid = i;break;
		}
		sum += a[i];
	}
	rpos = mid;
	ls = lnow = l/2-s[mid-1];
	if((l+1)/2==s[mid]||l/2==s[mid]){
		rs = rnow = s[mid+1]-(l+1)/2;rpos = mid+1; 
	}
	else{
		if(l%2==1){
			rs = rnow = s[mid]-(l/2)-1;
		}
		else{
			rs = rnow = s[mid]-(l/2);
		}
	}
	for(int i =mid;i>=1;i--){
		if(i!=mid){
			ls += a[i];
		}
//		cout<<ls<<" "<<rs<<"\n"; 
		while(ls>=rs){
			if(c[i]!=c[rpos]){
				ans += rnow;
			} 
			if(rpos+1>n)break;
			rpos++;
			rs += a[rpos];
			rnow = a[rpos];
		}
		if(rs>ls&&rs-rnow+1<=ls){
			if(c[i]!=c[rpos])ans += ls-(rs-rnow);
			rnow -= ls-(rs-rnow);
		} 
	}
	cout<<ans;
}
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b


5
1 a
1 a
2 a
81 b
3 c
*/
