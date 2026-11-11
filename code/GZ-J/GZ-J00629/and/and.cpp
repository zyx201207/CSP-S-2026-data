// GZ-J00629 µËÍûÔÆ
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[100005];
	int ma=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	if(m==1) cout<<ma;
	ma=0;
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
			ma=max(ma,a[i]&a[j]);
			}
		}
	}
	cout<<ma;
}
