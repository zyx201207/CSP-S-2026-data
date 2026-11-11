#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
char c[200005];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
    cin.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		
		//cout<<a[i]<<" "<<c[i]<<"\n";
	}
	for (int i=1,j=n;i<j;){
		if(c[i]==c[j]){
			long long minx=min(a[i],a[j]);
			a[i]-=minx;
			a[j]-=minx;
			if(a[i]==0){
				i++;
			}
			if(a[j]==0){
				j--;
			}
		}
		else {
			long long minx=min(a[i],a[j]);
			ans+=minx;
			a[i]-=minx;
			a[j]-=minx;
			//cout<<minx<<"\n";
			if(a[i]==0){
				i++;
			}
			if(a[j]==0){
				j--;
			}
		}
		//cout<<i<<" "<<j<<"\n";
	}
	cout<<ans;
	
	return 0;
} 
