#include<bits/stdc++.h>
#define ll long long
const int N=2*1e5+5;
using namespace std;
int a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	ll ans=0;
	for(int i=1,j=n;i<=j;){
		if(a[i]<a[j]){
			ans+=a[i]*(c[j]!=c[i]);
			a[j]-=a[i];
			a[i]=0;
			i++;
		}else{
			ans+=a[j]*(c[j]!=c[i]); 
			a[i]-=a[j];
			a[j]=0;
			j--;
		}
	}
	cout<<ans;
	return 0;
}

