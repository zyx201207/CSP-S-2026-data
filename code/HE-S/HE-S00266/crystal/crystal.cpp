#include<bits/stdc++.h>
using namespace std;
const long long N=1e8+10;
long long n,m,cnt=1,s=0,z=0;
long long a[N],b[N];
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(long long i=1;i<=n;i++){
		cnt=1;
		long long x=m;
		for(long long j=i+1;j<=n;j++){
			s=a[i]-a[j];
			if(x>=s){
				x-=s;
				cnt++;
			}else break;
			z=max(cnt,z);
		}
	}
	cout<<z;
	return 0;
} 
