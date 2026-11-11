#include "bits/stdc++.h"
using namespace std;
#define int long long
int n;
int a[200005];
char c[200005];
string str;
signed main(void){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	int h=1,t=n,ans=0,now1=a[1],now2=a[n];
	while(h<t){
		if(now1==now2){
			ans+=now1*(c[h]!=c[t]);
			h++,t--;
			now1=a[h],now2=a[t];
			continue;
		}
		if(now1<now2){
			ans+=now1*(c[h]!=c[t]);
			h++;
			now2-=now1;
			now1=a[h];
			continue;
		}
		if(now1>now2){
			ans+=now2*(c[h]!=c[t]);
			t--;
			now1-=now2;
			now2=a[t];
			continue;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
