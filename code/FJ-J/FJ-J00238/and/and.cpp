#include<bits/stdc++.h>
using namespace std;
int n,m,a[100010],ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	if(m==1){
		for(int i=0;i<n;i++) ans=max(ans,a[i]);
		cout<<ans;
		return 0;
	}else if(m==2){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				 ans=max(ans,a[i] & a[j]);
			}
		}
		cout<<ans;
		return 0;
	}else if(m==n){
		for(int i=0;i<n;i++) ans=ans & a[i];
		cout<<ans;
		return 0;
	}else{
		for(int i=0;i<n;i++) ans=max(ans,a[i]);
		for(int i=0;i<m;i++){
			int ansi=0,maxans=0;
			for(int j=0;j<n;j++){
				if((ans & a[j])>maxans) ansi=j,maxans=(ans & a[j]);
			}
			if(ansi!=0) a[ansi]=0;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
