#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100005];
int s[100005];
int sp[100005];
int sz[100005];
int shu[100005];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
	
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
   
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
    	cin>>a[i];
    	
	}
	
	sort(a,a+n);
	
	s[0]=a[0];
	for(int i=1;i<n;i++){
		s[i]=s[i-1]+a[i];
	}
	
	for(int i=0;i<n;i++){
		if((s[i]+m)%(i+1)==0 && (s[i]+m)/(i+1)>=a[i]){
			sp[i]=(s[i]+m)/(i+1);	
			shu[i]=i+1;
		}else if( (s[i]+m)/(i+1)>=a[i]){
			sp[i]=(s[i]+m)/(i+1);	
			shu[i]=i;
		}else continue;
		
		
	}
	
	int dd=-10;
	int da;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			da=shu[i];
			if(a[j]==sp[i]){
				da++;
			}
		}
		dd=max(dd,da);
	}

	cout<<dd;






return 0;
}

