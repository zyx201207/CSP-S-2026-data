#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Please return
#define AC 0
int n,m,a[1145140],k,f,maxx=-1,b[515411]={0};
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for (int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    if (n<=5000){
	for (int i=0;i<n;i++){
		k=m,f=1;
		for (int j=i-1;j>=0;j--){
		if (k>=a[i]-a[j]) f++,k-=a[i]-a[j];
}
		maxx=max(maxx,f);
	}
	cout<<maxx<<endl;
}
    else{
    	if (m>abs(a[0]-a[n-1])*n) cout<<m<<endl;
    	else{
    		if (m<=100000000){
				for (int i=0;i<n;i++) b[a[i]+200]++;
				for (int i=0;i<n;i++){
					k=m,f=0;
					for (int j=a[i];j>=-100;j--){
						if (k>=(a[i]-j)*b[j+200]&&b[j+200]!=0) f+=b[j+200],k-=(a[i]-j)*b[j+200];
						else if(k>=(a[i]-j)&&b[j+200]!=0) f+=k/(a[i]-j);
						
					}
					
					maxx=max(maxx,f);
				}
				
				cout<<maxx<<endl;
			}
			else{
				cout<<m;
			}
		}
	}
    
    Please AC;
}
