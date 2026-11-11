#include<bits/stdc++.h>
using namespace std;
long long n,a[200086],len,l,r,lc;
char c[200086],t[200086];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
    	cin>>a[i]>>t[i];
    	len+=a[i];
	}                 
	long long cnt=0;
	l=1;
	r=n;
	while(l<r){
		if(t[l]!=t[r]){
			lc=min(a[l],a[r]);
			if(a[l]>a[r]){
				r--;
				a[l]-=lc;
			}
			else if(a[l]<a[r]){
				l++;
				a[r]-=lc;
			}
			else if(a[l]==a[r]){
				l++;
				r--;
			}
			cnt+=lc;
		}
		else if(t[l]==t[r]){
			lc=min(a[l],a[r]);
			if(a[l]>a[r]){
				r--;
				a[l]-=lc;
			}
			else if(a[l]<a[r]){
				l++;
				a[r]-=lc;
			}
			else if(a[l]==a[r]){
				l++;
				r--;
			}
		}
		lc=0;
    }
    cout<<cnt;
	return 0;
}
