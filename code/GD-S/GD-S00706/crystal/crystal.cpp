#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],c[N],l=0,r=2,s=2,ans;
long long mx,sum;
int main(){
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)c[i]=a[i]+c[i-1];
	
	while(r<=n){
	//	cout<<l<<' '<<r<<' '<<a[r]*(s-1)-(c[r-1]-c[l])<<endl;
		if(a[r]*(s-1)-(c[r-1]-c[l])>m)l++,s--;
		else ans=max(ans,s),r++,s++;
		
		
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
