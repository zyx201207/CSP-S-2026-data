#include<bits/stdc++.h>
using namespace std;
#define int long long
#define push_back pb
#define first fi
#define second se 
int n,a[200005],c[200005],li=1,ri,cost;
char cc;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	ri=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>cc;
		c[i]=cc;
	}
	while(li<ri){
		if(a[li]<a[ri]){
			if(c[li]!=c[ri]){
				cost+=a[li];
			}
			a[ri]-=a[li];
			li++;
		}
		else if(a[li]==a[ri]){
			if(c[li]!=c[ri]){
				cost+=a[li];
			}
			li++;
			ri--;
		}
		else if(a[li]>a[ri]){
			if(c[li]!=c[ri]){
				cost+=a[ri];
			}
			a[li]-=a[ri];
			ri--;
		}
	}
	cout<<cost;
	return 0;
}
