#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    long long n,a[200005],zz=1;
    char c[200005];
    long long aa=0,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i]>>c[i];
        aa+=a[i];
    }
    long long xx=aa;
    char z[aa];
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=a[i];j++){
    		z[zz]=c[i];
    		zz++;
    	}
    }
    for(long long i=1;i<=aa/2;i++){
    	if(z[i]!=z[xx]){
    		ans++;
    		xx--;
    	}
    }
    cout<<ans;
}
