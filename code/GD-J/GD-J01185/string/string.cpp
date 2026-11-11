#include<bits/stdc++.h>
using namespace std;
int n;
long long m[200000+100];
char a[200000+100];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i]>>a[i];
	}
	long long ans=0;
	int l=1,r=n;
	while(l<=r){
		if(a[l]==a[r]){
			if(m[l]<m[r]){
				m[r]-=m[l];
				m[l]=0;
				l++;
			}
			else if(m[l]>m[r]){
				m[l]-=m[r];
				m[r]=0;
				r--;
			}
			else{
				m[l]=0;
				m[r]=0;
				l++,r--; 
			}
		}
		else{
			if(m[l]<m[r]){
				ans+=m[l];
				m[r]-=m[l];
				m[l]=0;
				l++;
			}
			else if(m[l]>m[r]){
				ans+=m[r];
				m[l]-=m[r];
				m[r]=0;
				r--;
			}
			else{
				ans+=m[l];
				m[l]=0;
				m[r]=0;
				l++,r--; 
			}
		}
	}
	cout<<ans;
	return 0;
} 


