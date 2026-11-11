#include<bits/stdc++.h>
using namespace std;
int n,m,a[5001000],b[1001000],c[1001000]={0},i,j,num=0,ans=-1,l=1;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(a[i]>=0) {
            b[a[i]]++;
		}else{
            c[abs(a[i])]++;
		}
	}
	for(int i=1;i<=n;i++)
        a[i]=0;
	for(int i=-100100;i<0;i++) {
        while(c[abs(i)]--) {
            a[++num]=i;
        }
	}
	for(int i=0;i<100100;i++) {
        while(b[i]--) {
            a[++num]=i;
        }
	}
	int s=a[1];
	for(int i=2;i<=n;i++) {
        if(a[i]*(i-1)-s<=m) {
            l++;
            ans=max(ans,l);
            s+=a[i];
        }else{
            l=0;
            s=0;
        }
	}
	cout<<ans;
	return 0;
}
