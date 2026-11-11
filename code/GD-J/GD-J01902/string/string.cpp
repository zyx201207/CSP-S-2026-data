#include <bits/stdc++.h>
using namespace std;
string lb,c[200020];
long long n,cnt,ans,la,b[200020];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i]>>c[i];
		cnt+=b[i];
	}
	for(int l=1,r=n+1;l<r;l++){
		if(b[l]<=la){
			la-=b[l];
			if(lb!=c[l])
				ans=ans+b[l];
		}
		else{
			while(b[l]!=0 and l<r){
				if(b[l]<=la){
					la-=b[l];
					if(lb!=c[l])
						ans=ans+b[l];
					break;
				}
				if(lb!=c[l])
					ans=ans+la;
				b[l]-=la;
				r--;
				la=b[r];
				lb=c[r];
			}
		}
		if(l>=r) break;
	}
	cout<<ans;
	return 0;
}
