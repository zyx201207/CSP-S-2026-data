#include<bits/stdc++.h>
using namespace std;
int a[200050],q[200050],h[200050];
char b[200050];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long t=0,m=0,r=1,l,ans=0;
	int n;
	cin>>n;
	l=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>b[i];
		t+=a[i];
	}
	for(int i=1;i<=n;i++){
		m+=a[i];
		if(m>t/2){
			if(m-a[i]<=t/2){
				if(t/2-m+a[i]>m-t/2){
					a[i]-=m-t/2;
					t-=m-t/2;
					q[i]=1;
				}
				else{
					a[i]-=t/2-m+a[i];
					t-=t/2-m+a[i];
					h[i]=1;
				}
			}
			else{
				h[i]=1;
			}
		}
		else{
			q[i]=1;
		}
	}
	long long u;
	for(int i=1;i<n;i++){
		if(q[i]==1&&h[i+1]==1) u=i;
	}
	long long s=0;
	while(s<t&&r<=u&&l>u){
		if(b[r]==b[l]){
			if(a[r]==a[l]){
				r++;
				l--;
				s+=a[r]*2;
			}
			else{
				if(a[r]>a[l]){
					s+=a[l]*2;
					a[r]-=a[l];
					l--;
				}
				else{
					s+=a[r]*2;
					a[l]-=a[r];
					r++;
				}
			}
		}
		else{
			if(a[r]>a[l]){
				s+=a[l]*2;
				a[r]-=a[l];
				ans+=a[l];
				l--;
			}
			else{
				if(a[r]==a[l]){
					s+=a[l]*2;
					l--;
					r++;
					ans+=a[l+1];
				}
				else{
					s+=a[r]*2;
					a[l]-=a[r];
					r++;
					ans+=a[r-1];
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
