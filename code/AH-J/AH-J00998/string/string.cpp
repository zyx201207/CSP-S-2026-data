#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],l,r,t,l2=1,r2,cnt;
char c[200005];
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	r2=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		r+=a[i];
	}
	while(l<r){
		if(c[l2]==c[r2]){
			l+=min(a[l2],a[r2]);
			r-=min(a[l2],a[r2]);
			if(a[l2]>a[r2]){
				a[l2]-=a[r2];
				r2--;
			}
			else if(a[l2]<a[r2]){
				a[r2]-=a[l2];
				l2++;
			}
			else {
				r2--;
				l2++;
			}
		}
		else{
			l+=min(a[l2],a[r2]);
			r=r-(min(a[l2],a[r2]));
			if(a[l2]>a[r2]){
				cnt+=a[r2];
				a[l2]-=a[r2];
				r2--;
			}
			else if(a[l2]<a[r2]){
				cnt+=a[l2];
				a[r2]-=a[l2];
				l2++;
			}
			else{
				cnt+=a[r2];
				r2--;
				l2++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
