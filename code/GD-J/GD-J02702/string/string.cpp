#include<bits/stdc++.h>
using namespace std;
char c[200005];
int a[200005],l,r,lh,rh,v,n;
long long s,ans;



int main(){
	freopen("string.in","r",stdin);freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	l=0;r=n+1;
	for(int i=1;l<=n;i++){
		if(lh==0){
			l++;
			lh=a[l];
		}
		if(rh==0){
			r--;
			rh=a[r];
		}
		v=min(lh,rh);
		if(c[l]!=c[r]){
			ans+=v;
		}
		lh-=v;
		rh-=v;
	}
	
	
	
	cout << ans/2;
	
	//fileclo();
	return 0;
} 
