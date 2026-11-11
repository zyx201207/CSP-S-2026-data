#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500008],b[200008],nn,n2=1e18+666,mm,x,y,ans=1,s=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		nn=max(nn,a[i]);
		n2=min(n2,a[i]);
		b[a[i]+100000]++;
	}sort(a+1,a+1+n);
	if(nn<=100008){
		for(int i=nn+100000;i>=100000+n2;i--){
			mm=m;
			x=i-1;
			s=b[i];
			while(mm>0 and x>=100000+n2){
				if(x>=100000+n2){
					//mm=mm-(i-x)*b[x];
					for(int j=1;j<=b[x];j++){
						if(mm-b[x]>=0 and b[x]){
							mm=mm-(i-x);
							s++;
						}
					}
					//cout<<mm<<' '<<(i-x)*b[x]<<' '<<x<<endl;
					x--;
				}
				//if(mm>=0 and b[x]){
				//	s++;
				//}
			}
			//cout<<s<<endl;
			ans=max(ans,s);
		}
	}else{
		x=1;
		mm=m;
		while(mm>=0){
			mm-=(a[n]-a[n-x]);
			//cout<<mm<<' '<<a[n-x]<<' '<<x<<endl;
			x++;
			if(mm>=0)
				ans++;
		}
	}
	cout<<ans;
	return 0;
} 
