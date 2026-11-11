#include<bits/stdc++.h>
using namespace std;
char b[1000005];
long long n,a[1000005],sum,maxn,ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		sum+=a[i];
		maxn=max(maxn,a[i]);
	}
	if((maxn<=50&&n<=2000)||(n<=200000&&maxn==1)){
		for(int i=1;i<=n;i++){
			while(a[i]--) s+=b[i];
		}
		long long l,r;
		if(sum%2==1){
			l=(sum-1)/2-1;
			r=(sum+1)/2;
		}else{
			l=sum/2-1;
			r=sum/2;
		}
		while(l>=0){
			if(s[l]!=s[r]) ans++;
			l--,r++;
		}
    }
	cout<<ans;
	return 0;
}
