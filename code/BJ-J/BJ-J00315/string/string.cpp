#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
char ch[200005];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i]>>ch[i];
    }
    int li=1;
    int ri=n;
    int ans=0;
    while(li<ri){
    	if(ch[li]==ch[ri]){
    		if(a[li]>a[ri]){
    			a[li]-=a[ri];
    			ri--;
    		}
    		else if(a[li]<a[ri]){
    			a[ri]-=a[li];
    			li++;
    		}
    		else{
    			li++;
    			ri--;
    		}
    	}
    	else{
    		if(a[li]>a[ri]){
    			ans+=a[ri];
    			a[li]-=a[ri];
    			ri--;
    		}
    		else if(a[li]<a[ri]){
    			ans+=a[li];
    			a[ri]-=a[li];
    			li++;
    		}
    		else{
    			ans+=a[li];
    			li++;
    			ri--;
    		}
    	}
    }
    cout<<ans;
    return 0;
}