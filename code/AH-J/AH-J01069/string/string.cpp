#include<bits/stdc++.h>
using namespace std;
string s,m;
char x;
long long t,l,a[200005],sum,i=0,mid,r,ans,tm;
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>t;
    while(t--){
    	i++;
    	cin>>a[i]>>x;
    	while(x==' '){
    		cin>>x;
		}
    	sum+=a[i];
    	for(int j=1;j<=a[i];j++){
    		s+=x;
		}
	}
	mid=(sum+1)/2;l=0;
	while(l<mid){
		l++;
		if(s[l]!=s[sum+1-l]){
			ans++;
		}
	}
	cout<<ans;		
    return 0;
}

