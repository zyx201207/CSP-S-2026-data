//GZ-S00391 岑巩县第一中学 吴先杰
#include <bits/stdc++.h>
using namespace std;
int a[5000010];
int b[5000010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	long long int n,m;
	bool fn=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	    cin>>a[i];
	}
	sort(a+1,a+n+1);
	 
	long long int left=1,right=n,mid=left+(right-left)/2;
	long long int t=1,x,tot=0,k=0,ans=1;
	while(left<=right){
		for(int i=mid;i>=1;i--){
			x=a[i]-a[mid];
			if(x<=a[mid]){b[t]=x;t++;}
			k++;
		}
		for(int i=1;i<=mid;i++){
			tot=tot-b[i];
			if(tot>m){fn=1;break;}
		}

		if(fn==1){ 
			right=mid-1;
			mid=left+(right-left)/2;
			k=0;tot=0;fn=0,t=1;
		}else{
			if(k>ans){ans=k;}
			left=mid+1;
			mid=left+(right-left)/2;
			k=0;tot=0;fn=0,t=1;
		}
	}
	
	cout<<ans;
	return 0;
 } 
