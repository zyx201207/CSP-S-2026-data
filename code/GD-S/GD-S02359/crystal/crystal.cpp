#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
int ans;
long long a[500005],b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
	} 
	int l=2,r=2;
	long long s=b[2],h=b[2];
	while(l<=r&&r<=n){
		if(s<=m){
			ans=max(ans,r-l+1);
			r++;
			s+=b[r]*(r-l+1);
			h+=b[r];
		}else{
			s-=h;
			h-=b[l];
			l++;
		}
//		cout<<l<<" "<<r<<endl;
//		cout<<ans<<" "<<sum<<endl;
	}
	cout<<ans+1;
	fclose(stdin);
	fclose(stdout);
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/
