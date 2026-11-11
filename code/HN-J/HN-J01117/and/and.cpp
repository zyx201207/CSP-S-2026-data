#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m,a[N];
long long t[N],cnt,mx,tt;
long long b[35];
map<long long,int>st;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int c=1,c0=0;
	for(int i=0;i<=31;i++){
		b[i]=c;
		c*=2;
	}
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=30;j++){
			if(a[i]==b[j]-1){
				t[++cnt]=a[i];
			}
		}
		if(a[i]==0)c0++;
		st[a[i]]++;
	}
	if(c0+m>n){
		cout<<0;
		return 0;
	}
	sort(a+1,a+n+1);
	sort(t+1,t+cnt+1);
	for(int i=n;i>=1;i--){
		if(st[a[i]]>=m){
			mx=a[i];
			break;
		}
	} 
	for(int i=cnt;i>=1;i--){
		if(cnt-i+1>m)break;
		if(i==cnt){
			tt=t[i];
		}else{
			tt&=t[i];
		}
	}
	cout<<max(mx,tt);
	return 0;
}

