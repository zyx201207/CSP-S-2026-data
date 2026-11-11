#include<bits/stdc++.h>
using namespace std;
const int N=200010;
long long n;
long long a[N];
char c[N];
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1,r=n;i<=n;i++){
		while(a[i]!=0){
			if(c[i]==c[r]){
				if(a[i]<=a[r]){
					a[r]-=a[i];
					a[i]=0;
					if(a[r]==0)r--;
				}else{
					a[i]-=a[r];
					a[r]=0;
					r--;
				}
			}else{
				if(a[i]<=a[r]){
					ans+=a[i];
					a[r]-=a[i];
					a[i]=0;
					if(a[r]==0)r--;
				}else{
					ans+=a[r];
					a[i]-=a[r];
					a[r]=0;
					r--;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
