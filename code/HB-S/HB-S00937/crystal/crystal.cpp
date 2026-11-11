#include<bits/stdc++.h>
using namespace std;
    long long m,n;

    int crystay[1000001];
    long long ans=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >>n>>m;
    for(int i=1;i<=n;i++){
		cin>>crystay[i];
	}
	int mid=n/2;
	int l=0,r=0;
	for(int i=mid;i>=1;i--){
		l+=crystay[mid]-crystay[i];
	}
	for(int i=n;i>=mid;i--){
		r+=crystay[i]-crystay[mid];
	}
	
	if(l+r==m) {
	cout <<n; 
	return 0;
	}
	if(l<r){
		if(l<=m){
			int j=mid+1;
			while(l>m){
				l+=crystay[j]-crystay[mid];
				j++;
			}
				ans=mid+j-1;
				cout<<ans;
			}
			else{
				int j=1;
				while(l<=m)	{
					l-=crystay[mid]-crystay[j];
					j++;
				}
				ans=mid-j;
				cout<<ans;
			}
		}
	else{
		if(r<=m){
		int j=mid-1;
		while(r>m){
			r+=crystay[mid]-crystay[j];
			j--;
		}
		ans=n-j;
		cout<<ans;
		}
	else{
		int j=mid+1;
		while(r<=m)	{
			l-=crystay[j]-crystay[mid];
			j++;
			}
		ans=mid-j;
		cout<<ans;
			}	
		}

	return 0;
}

