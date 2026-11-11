#include<bits/stdc++.h>
using namespace std;
long long n,sum;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	long long ans=0;
	int l=1,r=n,la=a[1],ra=a[n];
	while(l<=r){
//		cout<<l<<' '<<r<<' '<<ans<<'\n';
		if(c[l]!=c[r]){
			if(la<=ra){
				ans+=la;
				l++;
				ra-=la;
				la=a[l];
			}
			if(la>ra){
				ans+=ra;
				r--;
				la-=ra;
				ra=a[r];
			}
		}
		else{
			if(la<=ra){
				l++;
				ra-=la;
				la=a[l];
			}
			if(la>ra){
				r--;
				la-=ra;
				ra=a[r];
			}
		}
	}
	if(sum%2==1)ans--;
	cout<<ans;
	return 0;
} 
/*
游记？ 
关注Hamster_Emperor谢谢喵
签到题 
*/ 
