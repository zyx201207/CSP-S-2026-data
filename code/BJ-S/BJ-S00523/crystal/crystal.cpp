#include<bits/stdc++.h>
using namespace std;
long long n,m,l=0,a[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=n;i>=1;i--){
		long long z=i-1,p=m,g=0;
		while(1){
			int h=a[i]-a[z];
			if(h<p){
				p-=h;
				g++;
				z--;
			}
			else if(h==p){
				g++;
				break;
			}
			else{
				break;
			}
			if(z-1<0){
				break;
			}
		}
		if(g>l){
			l=g;
		}
	}
	cout<<l;
	return 0;
}
