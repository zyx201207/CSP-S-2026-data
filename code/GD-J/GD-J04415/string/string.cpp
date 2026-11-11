#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int N=2e5+100;
int n;
ll a[N];
ll ans;
char b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]; 
	}
	int i=1,j=n;
	while(i<j){
		if(b[i]==b[j]){
			ll tmp=min(a[i],a[j]);
			a[i]-=tmp;
			a[j]-=tmp;	
		}
		else{
			ll tmp=min(a[i],a[j]);
			ans+=tmp;
			a[i]-=tmp;
			a[j]-=tmp;	
		}
		if(a[i]==0) i++;
		if(a[j]==0) j--;
	}
	cout<<ans;
	return 0;
}

