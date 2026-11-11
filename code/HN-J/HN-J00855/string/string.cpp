#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+5;
int n;
int a[N];
ll ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	for(int i=1,j=n;i<j;){
		if(a[i]>=a[j]){
			if(c[i]!=c[j]){
				ans+=a[j];
			}
			a[i]-=a[j];
			j--;
		}	
		else{
			if(c[i]!=c[j]){
				ans+=a[i];
			}
			a[j]-=a[i];
			i++;
		}
	}
	cout<<ans;
	return 0;
}

