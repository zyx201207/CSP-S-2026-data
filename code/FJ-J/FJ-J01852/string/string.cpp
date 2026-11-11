#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],b[200005],num=1,ans;
string s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long x;
		cin>>x>>s[i];
		a[i]=num;
		b[i]=num+x-1;
		num+=x;
	}
	long long l=1,r=n;
	while(l!=r){
		if(s[l]!=s[r]){
			if(b[l]-a[l]+1>b[r]-a[r]+1){
				ans+=b[r]-a[r]+1;
				a[l]+=b[r]-a[r]+1;
				r--;
			}
			else if(b[l]-a[l]+1<b[r]-a[r]+1){
				ans+=b[l]-a[l]+1;
				b[r]-=b[l]-a[l]+1;
				l++;
			}
			else{
				ans+=b[l]-a[l]+1;
				if(r-l==1){
					cout<<ans;
					return 0;
				}
				r--;
				l++;
			}
		}
		else{
			if(b[l]-a[l]+1>b[r]-a[r]+1){
				a[l]+=b[r]-a[r]+1;
				r--;
			}
			else if(b[l]-a[l]+1<b[r]-a[r]+1){
				b[r]-=b[l]-a[l]+1;
				l++;
			}
			else{
				if(r-l==1){
					cout<<ans;
					return 0;
				}
				r--;
				l++;
			}
		}
	}
    cout<<ans;
	return 0;
}