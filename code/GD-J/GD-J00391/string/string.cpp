#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;

int n,a[200005];
char c[200005];
long long sum,suma[200005],ans;

void solve1(){
	for(long long i=1;i<=sum/2;i++){
		long long mr=sum-i+1;
		int x1=lower_bound(suma+1,suma+n+1,i)-suma;
		int x2=lower_bound(suma+1,suma+n+1,mr)-suma;
		if(c[x1]!=c[x2]){
			ans++;
		}
	}
	cout<<ans;
	return;
}


signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		suma[i]=suma[i-1]+a[i];
	}
	sum=suma[n];
	
	for(int i=1;i<=n;i++){
		int mr1=sum-suma[i-1];
		int mr2=sum-suma[i]+1;
		int x1=lower_bound(suma+1,suma+n+1,mr1)-suma;
		int x2=lower_bound(suma+1,suma+n+1,mr2)-suma;
		
		for(int j=x2;j<=x1;j++){
			if(c[j] != c[i]){
				if(mr2>suma[i]){
					int start=max(suma[j-1]+1,mr2);
					int end=min(suma[j],mr1);
					ans+=(end-start+1);
				}else{
					int start=max(suma[j-1]+1,mr2);
					int end=min(suma[j],mr1);
					ans+=(end-start+1);
				}
			}
		}
	}
	cout<<ans/2;
	return 0;
}










