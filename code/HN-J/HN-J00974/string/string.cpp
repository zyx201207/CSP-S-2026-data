#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;

#define int long long
int n,a[N];
char c[N];

//un
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);freopen("string.out","w",stdout);
	
	cin>>n;
	int m=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		m+=a[i];
	}
	int sum=0,j=n,k=0;
	for(int i=1;k<=m/2;i++){
		k+=a[i];
		while(a[i]>0){
			int v=min(a[i],a[j]);
			a[i]-=v;a[j]-=v;
			if(c[i]!=c[j]){
				sum+=v;
			}
			if(a[j]<=0){
				j--;
			}
		}
	}
	cout<<sum;
	return 0;
}

