#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n,m,a[500005],b[500005],ans,c,sum,d=1;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>=2&&a[i-1]+a[2]-a[1]==a[i]){
			d++;
		}
		b[i]=a[i]+b[i-1];

	}
	sort(a+1,a+n+1);
	if(d==n){
		for(int i=n;i>=1;i--){
			if(m>=b[i]){
				ans=i+1;
				break;
			}
		}
		cout<<ans;
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=i;j>=1;j--){
				for(int k=j;k<=i;k++){
					sum+=a[i]-a[k];
				}
				if(sum<=m){
					if(i-j+1>ans){
						ans=i-j+1;
					}
				}
				sum=0;
			}
		}
		cout<<ans;
	}
	return 0;
}
/*
     A             CCCCC      
    AA            C     C
   A  A          C       
  AAAAAA         C
 A      A         C     C
A        A         CCCCC
*/
