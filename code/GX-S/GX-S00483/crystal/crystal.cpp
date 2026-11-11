#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m,ans=0;
unsigned long long a[500005],hz[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >>n>>m;
	long long sryy;
	for(unsigned long long i=1;i<=n;i++){
        cin >>sryy;
        a[i]=sryy+1000000000005;
	}
	unsigned long long l,r,mid;
	sort(a+1,a+1+n);
	for(unsigned long long i=n;i>=1;i--){
        hz[i]=hz[i+1]+a[i];
	}
	for(unsigned long long i=n;i>=1;i--){
        l=1,r=i;
        while(l<=r){
            if(!(((a[i]*(i-r+1))-(hz[r]-hz[i+1]))<=m)){
                mid=r+1;
                break;
            }
            mid=(l+r+1)/2;
            if(l==r){
                if(((a[i]*(i-l+1))-(hz[l]-hz[i+1]))<=m){
                    mid=l;
                    break;
                }
            }
            if(((a[i]*(i-mid+1))-(hz[mid]-hz[i+1]))<=m){
                r=mid-1;
            }
            else{
                l=mid;
            }
        }
        ans=max(ans,(i-mid+1));
	}
	cout <<ans;
	return 0;
}
