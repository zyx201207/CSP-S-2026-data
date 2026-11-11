#include <bits/stdc++.h>
using namespace std;
int n;
long long x,y,yy,ans1,ans2,a[200005],c[200005],d[200005];
char b[200005];
string yyy;
int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    x = 1;
    bool xxx = 0;
    for(int i = 1;i<=n;i++) {
    	cin>>a[i]>>b[i];
    	if(a[i]>500) xxx = 1;
    	c[i] = x;
    	x+=a[i];
    	d[i] = x-1;
	}
	x--;
	y = x;
	x/=2;
	if(xxx == 0) {
		for(int i = 1;i<=n;i++) {
	    	yyy+=b[i];
		}
		string zzz;
	    if(y%2 == 0) {
	    	for(int i = 1;i<=x;i++) zzz+=b[i];
	    	int ccnntt = x;
	    	for(int i = x+1;i<=y;i++) {
	    		zzz+=b[ccnntt];
	    		ccnntt--;
			}
			for(int i = 1;i<=y;i++) {
				if(yyy[i]!=zzz[i]) ans1++;
			}
			cout<<ans1;
		}else {
			for(int i = 1;i<=x;i++) zzz+=b[i];
	    	int ccnntt = x;
	    	zzz+=b[x+1];
	    	for(int i = x+2;i<=y;i++) {
	    		zzz+=b[ccnntt];
	    		ccnntt--;
			}
			for(int i = 1;i<=y;i++) {
				if(yyy[i]!=zzz[i]) ans1++;
			}
			cout<<ans1;
		}
	}else {
		int z = 1,Z = n;
		while(c[z]<=x) {
			while(d[Z]>=max(x,y-d[z]+1)) {
				if(b[Z]!=b[z]) ans1+=(d[Z]-max(max(x,y-d[z]+1),c[Z])+1);
				Z--;
			}
			z++;
		}
		cout<<ans1;
	}
    return 0;
}

