#include<bits/stdc++.h>
#define int long long
using namespace std;
struct in{
	int time;
	char c;
}s[200005];
signed main(){
	//rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char b;
		cin>>a>>b;
		s[i].time=a;
		s[i].c=b;
	}
	int l=1,r=n,ans=0;
	bool flag=1;
	while(l<r){
		int a1=s[l].time,a2=s[r].time;
		char b1=s[l].c,b2=s[r].c;
		if(b1!=b2){
			if(a1>a2){
				r--;
				s[l].time-=a2;
				ans+=a2;
			}
			if(a1<a2){
				l++;
				s[r].time-=a1;
				ans+=a1;
			}
			if(a1==a2){
				r--;
				l++;
				ans+=a1;
			}
		}
		if(b1==b2){
			if(a1>a2){
				r--;
				s[l].time-=a2;
			}
			if(a1<a2){
				l++;
				s[r].time-=a1;
			}
			if(a1==a2){
				r--;
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
