#include <bits/stdc++.h>
using namespace std;
const long long  N = 1e18+10;
long long a[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,c=0,cnt=0,l=0,maxn=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=0;i<n;i++){
		cnt=0,c=0,l=0;
		for(int j=0;j<=i;j++){
				c+=a[i]-a[j];
				if(c<=m)
					l+=1;
				else{
					c=a[i]-a[j];
					l=1;
				}
				if(l>cnt){
					cnt=l;
				}
			}
		if(cnt>maxn){
			maxn = cnt;
		}
	}
	cout<<maxn;
	return 0;
}
