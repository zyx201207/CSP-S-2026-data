#include <bits/stdc++.h>
using namespace std;
const int f=2*1e6;long long int d=0,g,h,z=0,ans=0;
int n,a,w;char c[f];
long long int r[f];
long long int e[f];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;w=n;
	for (int i=1;i<=n;i++){
		cin>>a>>c[i];
		r[i]=d+1;
		d+=a;
		e[i]=d;
	}
	z=(d+1)/2;
	for (int i=1;r[i]<=z;i++){
		g=r[i];h=min(e[i],z);
		while (e[w]<=d+1-h){
			w++;
		}
		while (e[w]>=d+1-h){
			if (c[w]!=c[i]){
				ans+=e[w]-max(r[w],d+1-h)+1;
			}
			w--;
		
		}
		
	}
	cout<<ans;
	return 0;
}
