#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],v,cnt,ans,res;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	while(v<=(1<<n)){
		v++;
		bool flag=0;
		res=0,cnt=0;
		for(int i=1;i<=n;i++) if((v>>(i-1))%2!=0) cnt++;
		if(cnt==m){
			for(int i=1;i<=n;i++){
				if((v>>(i-1))%2!=0){
					if(flag==0){res=a[i];flag=1;}
					else res&=a[i];
				}
			}
		}
		ans=max(ans,res);
	}
	cout<<ans;
	return 0;
} 
