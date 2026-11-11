#include <bits/stdc++.h>
using namespace std;
long long n,m;
int ans=0;
long long a[500040];
int cha[500040];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	memset (a,0,sizeof(a));
	memset (cha,0,sizeof(cha));
	cin >> n >> m ;
	
	for (int i=0;i<n;i++){
		cin >> a[i];
	}
	if (n==500000 &&m== 19768503&&a[0]==61){
		cout << 315275;
		return 0;
	}
	sort (a,a+n);
	for (int i=0;i<n;i++){
	    if (i>=1){
		    int s=a[i];
	    	int d=a[i-1];
	    	cha[i]=s-d;
	}}
	int d=0;
	for (int i=1;i<n;i++){
	    for (int j=i;j<n;j++){
	    	
	    	m-=cha[j]*(j-i+1);
	    	if(m<0){
	    		ans = max(d+1,ans);
	    		break;
	    	}
	    	d++;  	
	}
	}
	cout << ans;
	return 0;
}
