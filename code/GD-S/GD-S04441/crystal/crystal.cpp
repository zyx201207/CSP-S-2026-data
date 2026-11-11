#include<bits/stdc++.h>
using namespace std;
int n,m,ma;
long long su[500005],a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		su[i]=su[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=i,r=n;
		while(l<r){
			int mid=(l+r+1)/2,ne=a[mid]*(mid-i+1)-su[mid]+su[i-1];
			if(ne<=m){
				l=mid;
			}
			else{
				r=mid-1;
			}
		}
		ma=max(ma,l-i+1);
	}
	cout<<ma;
	return 0;
} 
