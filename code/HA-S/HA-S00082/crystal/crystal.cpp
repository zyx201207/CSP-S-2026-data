#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000001],maxx=-1e18,gongcha;
bool f=0,ff=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];    
	gongcha=a[2]-a[1];
	for(long long i=3;i<=n;i++){
		if(a[i]-a[i-1]!=gongcha) f=1;
	} 
	sort(a+1,a+n+1);
	if(f==1){
		for(long long i=2;i<=n;i++){
			long long s=0,s2=0;
			for(long long j=1;j<i;j++){
				if(a[i]!=a[j]){
					s+=a[i]-a[j];
					if((s>=0)&&(m-s)>=0){
						s2++;
					}
				}else s2++;
			}
			s2++;
			maxx=max(maxx,s2);
		}
		cout<<maxx;	
		return 0;
	}else{
		for(long long i=2;i<=n+1;i++){
			long long s=i*(i-1)/2*gongcha;
			if(m>=s){
				maxx=max(maxx,i);
			}else break;
		}
		cout<<maxx;
		return 0;
	}
	return 0;
}
