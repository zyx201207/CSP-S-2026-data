#include <bits/stdc++.h>
using namespace std;
long long a[500001];
long long cnt=1,sum,result;
long long maxn=-1e12,sym,bol;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1]){
			cnt++;
			sym=a[i];
		}
		else{
			if(cnt>maxn){
				maxn=cnt;
				sym=a[i];
				bol=i-cnt+1;
			}
			cnt=1;
		}
	}
	if(maxn==1){
		sym=a[n/2+1];
		bol=n/2+1;
	}
	if(bol==1){
		bol+=cnt;
		sym=a[bol];
	} 
	for(int i=bol-1;i>=1;i--){
		if(sum+sym-a[i]<=m){
			sum+=sym-a[i];
			result++;
		} 
	}
	cout<<result+maxn;
	return 0;
} 
