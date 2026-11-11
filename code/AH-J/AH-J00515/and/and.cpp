#include<bits/stdc++.h>
using namespace std;
int n,m,a[2001],mx=-1,num;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		if(i==1)
			num=a[i];
		else
			num&=a[i];
	}
	if(m==1){
		cout<<mx;
		return 0;
	}else if(m==2){
		mx=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				int x=(a[i]&a[j]);
				if(x>mx){
					mx=x;
				}
			}
		}
		cout<<mx;
	}else if(m==n){
		cout<<num;
	}else{
		cout<<mx;
	}
	return 0;
}
