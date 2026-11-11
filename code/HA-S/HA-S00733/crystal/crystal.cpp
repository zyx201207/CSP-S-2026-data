#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005],maxx=0,w=1,p,c,cnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=a[i]-a[i-1];
	}
	for(int i=1;i<n;i++){
		c=m;w=1;p=i+1;cnt=1;
		while(c>=0&&p<=n){
			if(c>=s[p]*w){
				c=c-(s[p]*w);
				w++;
				cnt++;
				p++;
			}else{
				c=-1;
			}
			
		}
		maxx=max(maxx,cnt);
	}
	cout<<maxx;
	return 0;
}
