#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n;
long long a[N];
long long len,mid;
char c[N];
int cnt;
long long hh=1,tt;
int h,t;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	h=1,t=n;
	tt=len;
	mid=len/2;
	for(int i = 1;mid>a[i];i++){
		mid-=a[i];
		cnt=i; 
	}
	cnt++;
	while(h<t){
//		cout<<h<<" "<<hh<<" "<<t<<" "<<tt<<" "<<ans<<endl;
		if(a[h]<a[t]){
			if(c[h]!=c[t]){
				ans+=a[h];
			}
			a[t]-=a[h];
			h++;
			hh+=a[h];
			tt-=a[h];
		}
		else if(a[h]>a[t]){
			if(c[h]!=c[t]){
				ans+=a[t];
			}
			a[h]-=a[t];
			t--;
			hh+=a[t];
			tt-=a[t];
		}
		else {
			if(c[h]!=c[t]){
				ans+=a[t];
			}
			h++;hh+=a[t];
			t--;tt-=a[t];
		}
	}
	cout<<ans;
	return 0;
} 
