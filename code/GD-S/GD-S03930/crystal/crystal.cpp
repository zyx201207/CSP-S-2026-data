#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
const int INF=0x3f3f3f3f;
int n,m;
int a[N],d[N],cf[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		
		d[i]=abs(a[i]-a[i-1]);
//		cout<<d[i]<<endl;
	}
	unsigned long long st=1,en=1,cnt=0,maxx=1;
	for(int i=2;i<=n;i++){
		en=i;
		cnt+=d[i]*(en-st);
		if(cnt>m){
			while(cnt>m&&en>st){
				cnt-=abs(a[en]-a[st]);
				st++;
			}
		}
//		if(cnt<=0)
//		cout<<st<<"~"<<en<<" "<<cnt<<endl;
		maxx=max(maxx,en-st+1);
	}
	cout<<maxx;
	return 0;
}
