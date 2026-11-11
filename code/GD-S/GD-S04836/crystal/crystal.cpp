#include <bits/stdc++.h>
using namespace std;
int n,m,ans=0,j=0,z,sum=0;
int a[500002],b[500002];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	while(j<n){
		ans=0;
		for(int i=j+1;i<n;i++){
			ans+=a[j]-a[i];
		}
		j++;
		if(ans<=m){
			z=j-1;
			while(a[j]==a[z]){
				sum++;
				z--;
			}
			cout<<n-j+sum;
			break;
		}
	}
	
	return 0;
}
