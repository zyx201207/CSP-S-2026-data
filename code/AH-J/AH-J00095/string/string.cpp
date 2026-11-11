#include<bits/stdc++.h>
#define int long long
using namespace std;
const int dd=2e5+5;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[dd],c[dd];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(c[i]==c[i-1]) cnt=0;
		else{
			cnt++;
		}
		while(c[i]!=c[n]){
			cnt++;
		    c[n]=c[n-1];
	   }
	   
	}
    if(cnt==0)cout<<0<<endl;
	if(cnt!=0)cout<<cnt<<endl;
	
	return 0;
}
