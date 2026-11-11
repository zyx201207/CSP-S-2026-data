//GZ-S00344 贵阳市第九中学 张修涵 
#include <bits/stdc++.h>
using namespace std;
int n,m,qw=0,ew=0,cnt[10000000];
int a[10000000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]<a[j]){
				qw=a[i];
				ew=a[j];
				a[i]=ew;
				a[j]=qw;
				
			}
		}
				
	}
	ew=m;
	for(int i=1;i<=n;i++){
		
		for(int j=i+1;j<=n;j++){
			if(m>=(a[i]-a[j])){
				cnt[i]++;
				m-=a[i]-a[j];
				if(i==3){
					
					
				}
			}
			
		}
		m=ew;		
	}	
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(cnt[i]<cnt[j]){
				qw=cnt[i];
				ew=cnt[j];
				cnt[i]=ew;
				cnt[j]=qw;
				
			}
		}
				
	}
	cout<<cnt[1]+1;
	return 0;
}
