#include<bits/stdc++.h>
using namespace std;
char c[200010];
int num[200010];
long long ans=0;
int n;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i]>>c[i];
	}
	int l=1,r=n,ln=num[l],rn=num[r];
	while(l<r){
		if(ln<rn){
			if(c[l]!=c[r]){
				ans+=ln;
			}
			rn-=ln;
			l++;
			ln=num[l];
		}
		else{
			if(ln>rn){
				if(c[l]!=c[r]){
					ans+=rn;
				}
				ln-=rn;
				r--;
				rn=num[r];
			}
			else{
				if(c[l]!=c[r]){
					ans+=ln;
				}
				l++;
				r--;
				ln=num[l];
				rn=num[r];
			}
		}
	}
	cout<<ans;
	return 0;
}
