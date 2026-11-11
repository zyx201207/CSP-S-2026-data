#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n,m,a[100005],maxx=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		int andd;		
		andd=a[i]^a[i-1];
		if(andd>maxx)maxx=andd;		
	}
	cout<<maxx;
}
