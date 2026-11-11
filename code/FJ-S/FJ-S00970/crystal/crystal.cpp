#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
long long a[N];
int sum[N];
long long b[N];
int cnt;
int maxx;
int maxx1;
int l,r;
long long t;
int num[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long p=m;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	sum[++cnt]=1;
	maxx=1;
	for(int i=2;i<=n;i++){
		if(a[i]!=a[i-1]){
			sum[++cnt]=1;
			b[cnt]=a[i]-a[i-1];
		}
		else sum[cnt]++;
		maxx=max(maxx,sum[cnt]);
	}
	for(int i=1;i<=cnt;i++) num[i]+=num[i-1]+b[i];
	l=1,r=1;
	int x;
	x=sum[1];
	int t1;
	while(r<=cnt){
	    t1=maxx1*b[r]+t-m;
		maxx1+=sum[r];
		while(t1>0){
			if(t1/(num[r]-num[l])<x){
				if(t1%(num[r]-num[l-1])==0){
					maxx1-=t1/(num[r]-num[l-1]);
					x-=t1/(num[r]-num[l-1]);
					t1=0;
				}
				else{
					maxx1-=(t1/(num[r]-num[l])+1);
					x-=(t1/(num[r]-num[l])+1);
					t1-=(t1/(num[r]-num[l])+1)*(num[r]-num[l]);
				}
				if(x==0){
					++l,x=sum[l];
				}
			}
			else{
				t1-=x*(num[r]-num[l]);
				maxx1-=x;
				++l;
				x=sum[l];
			}
		}
		t=m+t1;
		++r;
		maxx=max(maxx,maxx1);
	}
	cout<<maxx;
	return 0;
}
