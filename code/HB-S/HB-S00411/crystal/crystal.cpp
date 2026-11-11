#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,cnt,p=1;
long long a[N],s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
		cin>>a[i];
		s[i]=a[i]-a[i-1];
    }
    sort(a+1,a+n+1);
    for(long long i=2;i<=n;i++){
		long long ans=0;
		bool f=0;
		for(int j=1;j<i;j++){
			if(ans>m){
				f=1;
				break;
			ans+=a[i]-a[j];
			}
			
	    }
	    if(!f){cnt=ans;p++;}
	    else break;
	    ans=0;
    }
    cout<<p;
    return 0;
}
