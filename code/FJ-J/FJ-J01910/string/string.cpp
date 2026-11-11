#include<bits/stdc++.h>
using namespace std;
const int MAXN=2E5+5;
int n,l,r,h,t;
int a[MAXN];
char c[MAXN];
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i]>>c[i];
	l=1,r=n;
	h=t=1;
	while(l<r){
		if(c[l]!=c[r]){
			if((a[l]-h+1)>(a[r]-t+1)){
//				cout<<1<<endl;
				ans+=a[r]-t+1;
				h+=a[r]-t+1;
				r--;
				t=1;
//				cout<<l<<' '<<r<<' '<<h<<' '<<t<<endl; 
			}else if((a[l]-h+1)<(a[r]-t+1)){
//				cout<<2<<endl;
				ans+=a[l]-h+1;
				t+=a[l]-h+1;
				l++;
				h=1;
//				cout<<l<<' '<<r<<' '<<h<<' '<<t<<endl; 
			}else if((a[l]-h+1)==(a[r]-t+1)){
//				cout<<3<<endl;
				ans+=a[l]-h+1;
				l++;
				r--;
				h=t=1;
//				cout<<l<<' '<<r<<' '<<h<<' '<<t<<endl; 
			}
		}else{
			if((a[l]-h+1)>(a[r]-t+1)){
//				cout<<4<<endl;
				h+=a[r]-t+1;
				r--;
				t=1;
//				cout<<l<<' '<<r<<' '<<h<<' '<<t<<endl; 
			}else if((a[l]-h+1)<(a[r]-t+1)){
//				cout<<5<<endl;
				t+=a[l]-h+1;
				l++;
				h=1;
//				cout<<l<<' '<<r<<' '<<h<<' '<<t<<endl; 
			}
			else if((a[l]-h+1)==(a[r]-t+1)){
//				cout<<6<<endl;
				l++;
				r--;
				h=t=1;
//				cout<<l<<' '<<r<<' '<<h<<' '<<t<<endl; 
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
3
1 k
5 b
5 c
*/
