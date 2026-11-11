#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1000005];
int b[1000005];
char c[200005];
char d[200005];
signed main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
    }
	
	if(n==1){
		cout<<"0";
		return 0;
	}
	int ans=0;
	for(int i=0;i<n;i++){
		ans+=a[i];
	}
	ans=ans/2;
	b[0]=a[0];
	int p=0;
	
	for(int i=0;i<n;i++){
		if(c[i]==c[i+1]){
			b[p]=b[p]+a[i+1];
			d[p]=c[i];
		}else p++;
		
		
		
	}
	int ins=0;
	bool sh=true;
	
	for(int i=0;i<p;i++){
		
		
		
		
		if(b[i]==b[p-i] && d[i]==d[p-i]){
			continue;
		}else if(d[i]==d[p-i]){
			
			ins+=abs(b[i]-b[p-1]);
			sh=false;
			
		}else if(b[i]==b[p-i] && d[i]!=d[p-i]){
			sh=false;
			ins+=b[p-1];
	
		
		}
	
	
	}
	
	
	
	if(sh){
		cout<<"0";
		
	} else{
		if(ins>ans){
			cout<<ans;
		}else cout<<ins;
		
	} 
	
	
	

return 0;
}


