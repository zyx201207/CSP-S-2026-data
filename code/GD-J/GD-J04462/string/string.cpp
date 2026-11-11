#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
int n;
int a[N];
char b[N];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1,j=n;i<j;){
		int sma=min(a[i],a[j]);
		if(b[i]!=b[j]){
			ans+=sma;
		}
		a[i]-=sma;
		a[j]-=sma;
		if(!a[i])i++;
		else j--;
	}
	cout<<ans;
	return 0;
}
