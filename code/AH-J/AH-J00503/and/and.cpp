#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
 	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[n];
	}
	
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		int l=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]&a[j]>l){
					l=a[i]&a[j];
				} 
			}
		}
		cout<<l;
		return 0;
	}
	if(m==n-1){
		int l=0,idx=1;
		for(int i=1;i<=n;i++){
			int w=0,aa=a[i];
			while(aa){
				if(aa%2==0){
					w++;
				}
				aa/=2; 
			} 
			if(w>l){
				l=w;
				idx=i;
			}
		} 
		int ans=a[idx!=1?1:2];
		for(int i=1;i<=n;i++){
			if(i!=idx){
				ans&=a[i];
			}
		}
		cout<<ans;
		return 0;
	}
	if(m<=n){
		int l=a[1];
		for(int i=1;i<=n;i++){
			if(a[i]>l){
				l=a[i];
			} 
		}
		cout<<l;
		return 0;
	}
	return 0;
}
