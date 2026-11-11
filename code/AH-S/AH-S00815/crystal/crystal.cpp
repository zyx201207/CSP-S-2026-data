#include<bits/stdc++.h>
using namespace std;
long long a[500005];
unsigned long long n,m,s[500005],sum1,t1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
        cin>>a[i];
        a[0]=a[i];
        if(a[i]!=a[i-1]){
            t1=1;
        }
	}
	if(t1==0){
        cout<<n;
        return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
        s[i]=a[i+1]-a[i];
	}
	long long l=1,maxx=1,sum=0,ans=1;
	for(register int r=1;r<n;r++){
        sum1+=s[r];
        sum+=s[r]*maxx;
        maxx++;
        if(sum>m){
            while(sum>m&&l<=r){
                sum-=sum1;
                sum1-=s[l];
                l++;
                maxx--;
            }
        }
        ans=max(ans,maxx);
	}
	cout<<ans;
    return 0;
}
