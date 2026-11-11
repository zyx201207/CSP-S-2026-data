#include<bits/stdc++.h>
using namespace std;
int a[200005];
long long n1=0;
int  n;
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i]>>b[i];
    	n1+=a[i];
    }
    n1=n1/2;
    long long ans=0;
    long long l=1,r=n;
    long long h=0;
    for(int i=1;;i++){
    	if(l==r){
    		break;
    	}
    	if(b[l]==b[r]){
    		h+=min(a[l],a[r]);
    		if(a[l]>a[r]){
    			a[l]-=a[r];
    			r--;
    		}else if(a[l]<a[r]){
    			a[r]-=a[l];
    			l++;
    		}else{
    			r--;
    			l++;
    		}
    	}else{
    		ans+=min(a[l],a[r]);
    		h+=min(a[l],a[r]);
    		if(a[l]>a[r]){
    			a[l]-=a[r];
    			r--;
    		}else if(a[l]<a[r]){
    			a[r]-=a[l];
    			l++;
    		}else{
                r--;
                l++;
    		}
    	}
    	if(h==n1)break;
    }
    cout<<ans;
	return 0;
}
//3
//2 a
//2 b
//1 c
