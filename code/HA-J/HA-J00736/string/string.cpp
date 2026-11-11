#include<bits/stdc++.h>

using namespace std;
long long n,d[200100],mid,ans=0,o;
char c[200100];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>d[i]>>c[i];
		mid+=d[i];
	}
	long long l=1,r=n;
	mid/=2;
	for(long long i=1;i<=n;i++){
		long long t=d[i];
		bool tc=0;
		if(o+d[i]>=mid){
			t=mid-o;
			tc=1;
		}else{
			o+=d[i];
		}
		for(;r>=1;r--){
			t-=d[r];
			if(t>0){
				if(c[i]!=c[r]){
					ans+=d[r];
					//cout<<ans<<i<<j<<' ';
				}
			}else{
				t+=d[r];
				d[r]-=t;
				if(c[i]!=c[r]){
					ans+=t;
					//cout<<ans<<i<<j<<' ';
				}break;
			}
			
		}if(tc)break;
	}cout<<ans;


	return 0;
}

