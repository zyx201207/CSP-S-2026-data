#include <bits/stdc++.h>
using namespace std;
int a[200005];
int ans=0;
int f[200005];
int aaa(int b,int n,int m){
	if(f[b-1]==n){
		if(b==m){
			int aa=a[f[0]-1];
			for(int i=1;i<b;i++){
				aa=aa&f[i]-1;
			}
			if(aa>ans){
				ans=aa;
			}
		}
		return 0;
	}
	if(b==m){
			int aa=a[f[0]-1];
			for(int i=1;i<b;i++){
				aa=aa&a[f[i]-1];
			}
			if(aa>ans){
				ans=aa;
			}
		}
		return 0;
	b++;
	for(int i=f[b-1]+1;i<=n;i++) {
		f[b-1]=i;
		aaa(b,n,m);
	}
}
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int b;
		cin>>b;
		a[i]=b;
	}
	if(m==n){
		ans=a[0]&a[1];
		for(int i=2;i<n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
	}else if(m==1){
		for(int i=0;i<n;i++){
			if(a[i]>ans){
				ans=a[i];
			}
		}
		cout<<ans;
	}else{
		for(int i=0;i<n;i++){
			f[0]=i;
			aaa(1,n,m);
		}
	}
	cout<<ans;
}
