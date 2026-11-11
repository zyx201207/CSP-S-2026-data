#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int a[200005];
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int t=b[1];
	bool f=true;
	for(int i=1;i<=n;i++){
		if(b[i]!=t)f=false;
	}
	if(f){
		cout<<0;
		return 0;
	}
	long long ans=0;
	int l=n;
	for(int i=1;i<=n/2;i++){
		while(a[i]!=0){
			if(b[i]!=b[l]){
				if(a[i]>a[l]){
					ans+=a[l];
					a[i]-=a[l];
					l--;
				}
				else {
					ans+=a[i];
					a[i]=0;
				}
		}
		else{
			ans+=abs(a[i]-a[l]);
			l--;
			a[i]=0;
			}
		}
	}
	cout<<ans;
	return 0;
}
