#include<bits/stdc++.h>
using namespace std;

long long a[10000000],n,m;
long long cnt=-1,cns;
int anc(long long s,long long j){
	if(s==m){
		cnt=max(cns,cnt);
		return cnt;
	}
	for(int i=j+1;i<=n;i++){
		int y=cns;
		cns&=a[i];
		anc(s+1,i);
		cns=y;
	}
	return cnt;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int b,c=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==2){
		long long y=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				y=a[i]&a[j];
				cnt=max(cnt,y);
			}
		}
		cout<<cnt;
		return 0;
	}
	if(m==n){
		int y=a[1];
		for(int i=2;i<=n;i++){
			y=y&a[i];
		}
		cout<<y;
		return 0;
	}
	if(m==n-1){
		long long y=a[1];
		for(int i=2;i<=n;i++){
			y=a[1];
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				y=y&a[i];
			}
			cnt=max(y,cnt);
		}
		y=a[2];
		for(int i=2;i<=n;i++){
			y&=a[i];
		}
		cnt=max(cnt,y);
		cout<<cnt;
		return 0;
	}
	if(n<=20){
		for(int i=1;i<=n;i++){
			cns=a[i];
			anc(1,i);
		}
		cout<<cnt;
		return 0;
	}
	cout<<1;
	return 0;
}
