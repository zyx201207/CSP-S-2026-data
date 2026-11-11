#include<bits/stdc++.h>
using namespace std;
const int N=1e5*2+10;
long long n,m,a[N]={0},ans=0,o=0,maxn=0;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n;i>=2;i--){
		o=m;bool u=true;
		for(int j=i-1;j>=1;j--){
			o=o-abs(a[i])+abs(a[j]);
			if(o>=0){
				if(u){
					ans=2;
					u=false;
				}
				else ans++;
			}
			if(o<0) break;
		}
		if(maxn<=ans)maxn=ans;
		ans=0;
	}
	cout<<maxn;
}
