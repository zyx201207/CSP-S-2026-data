#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int n,a[MAXN],s[MAXN];
long long m;
bool check(int num){
	for(int i=num-1;i<n;++i){
		long long ave=a[i];
		long long total=s[i+1]-s[i-num+1];
		if(ave*num<=total+m){
			return 1;
		}
	}return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i){
		scanf("%d",&a[i]);
	}sort(a,a+n);
	for(int i=1;i<n;++i){
		s[i]=s[i-1]+a[i-1];
	}
	int l=0,r=n,ans=0;
	while(r-l>1){
		int mid=(l+r)>>1;
		if(check(mid)){
			l=mid;
			ans=mid;
		}else{
			r=mid-1;
		}
	}
	printf("%d",ans);
	return 0;
}
