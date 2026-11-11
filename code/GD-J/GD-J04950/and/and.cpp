#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int v[200005];
int ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int now=30;
	int flag=0;
	while(now--){
	
		int sum=0;
		for(int i=1;i<=n;i++){
			if(flag==0){
				if(!v[i]&&a[i]>=int(pow(2,now))){
				//	a[i]-=int(pow(2,now));
			
					sum++;
					v[i]=1;
				}	
			}
			if(flag==1&&v[i]&&a[i]>=int(pow(2,now))){
				//a[i]-=int(pow(2,now));
				sum++;
				
			}
		}
		if(flag==0){
			if(sum>=m){
				flag=1;
				ans+=pow(2,now);
				for(int i=1;i<=n;i++){
					if(v[i]&&a[i]<int(pow(2,now))){
						v[i]=0;
					}
					if(v[i]&&a[i]>=int(pow(2,now))){
						a[i]-=int(pow(2,now));
					}
				}
			}else{
				for(int i=1;i<=n;i++){
					if(v[i]&&a[i]>=int(pow(2,now))){
						a[i]-=int(pow(2,now));
						v[i]=0;
					}
				}
			
			}
		}else{
			if(sum>=m){
				flag=1;
				ans+=pow(2,now);
				for(int i=1;i<=n;i++){
					if(v[i]&&a[i]<int(pow(2,now))){
						v[i]=0;
					}
					if(v[i]&&a[i]>=int(pow(2,now))){
						a[i]-=int(pow(2,now));
					}
				}
			}
		}
		
	}
	cout<<ans;
	return 0;
} 
