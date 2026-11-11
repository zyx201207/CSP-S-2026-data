#include<bits/stdc++.h>
using namespace std;
int a[200000+25];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,l=-1008,f=448,h=0,ans;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
		if(m==1){
			for(int i=1;i<=n;i++){
				l=max(l,a[i]);
			}
			cout<<l;
			return 0;
		}
		//else if(m==2){
		//	sort(a+1,a+n+1);
	//	cout<<(a[n]&a[n-1]);
		//	return 0;
		//}
		else{
			sort(a+1,a+n+1);
				for(int i=1;i<=n;i++){
					if(i==1){
						ans=a[n]&a[n-1];
					}
					else{
						ans=a[n]&a[n-i]&ans;
						cout<<ans;
					}
				}
			
			return 0;
		}
	//for(int i=1;i<=n;i++){
			//l=max(l,a[i]);
			//f=min(f,a[i]);
	//}
		/*for(int i=1;i<n;i++){
			if(a[i+1]-a[i]==0) {
			h=1;cout<<h;}
			else {
			h=0;
			break;
			}
		}
		if(h==1){
			int c=m/2;
			if(m%2==0){
				for(int i=1;i<=c;i++){
					if(i==1){
						ans=a[1]&a[n-1+1];
					}
					else{
						ans=a[i]&a[n-i+1]&ans;
						cout<<a[i]<<ans;
					}
				} 
			}
			cout<<ans;
		}*/
	    
	return 0;
}
