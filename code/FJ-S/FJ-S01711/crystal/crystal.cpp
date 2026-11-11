#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m;
long long a[N],b[N],c[N];
int mx=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i = n;i <= n;i++){
		int x=0;
			for(int j=i;j <= i;j++){
				c[i]=a[i]-a[j];
				}
				if(c[i]>=m){
					x=1;
					break;
			}
			if(x==1){
				break;
			}
		}
	for(int i = 1;i <= n;i++){
		for(int j = i+1;j <= n;j++){
			if(c[j]<=m){
				mx=max(mx,i);
			}
		}
		
	}
	cout<<mx;
	return 0;
}
