#include <bits/stdc++.h>
using namespace std;
const int N=1e6+3;
int n;
long long a[N];
char b[N];
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int o=1;
	int o2=n;
	while(o<o2){
		if(b[o]!=b[o2]){
			if(a[o]==a[o2]){
				ans+=a[o];
				o+=1;
				o2-=1;
			}
			else if(a[o]>a[o2]){
				ans+=a[o2];
				a[o]-=a[o2];
				o2-=1;
			}
			else{
				if(a[o2]>a[o]){
					ans+=a[o];
					a[o2]-=a[o];
					o+=1;
				}
			}
		}
		else{
			if(a[o]==a[o2]){
				o+=1;
				o2-=1;
			}
			else if(a[o]>a[o2]){
				o2-=1;
			}
			else{
				if(a[o2]>a[o]){
					o+=1;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
