#include<bits/stdc++.h>
using namespace std;
int n,m,p,ma,a[1001010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
		if(i==1)p=a[i];
		else p=p&a[i];
	}
	if(m==1){
		cout<<ma;
		return 0;
	}
	if(m==n){
		cout<<p;
		return 0;
	}
	if(m==2){
		ma=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ma=max(ma,a[i]&a[j]);
			}
		}
		cout<<ma;
		return 0;
	}
	ma=0;
	for(int i=1;i<(1<<n);i++){
		int p=-1,num=0;
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				num++;
				if(p==-1){
					p=a[j+1];
				}else p&=a[j+1];
				if(num>m)break;
			}
		}
		if(num!=m)continue;
		ma=max(ma,p);
	}
	cout<<ma;
	return 0;
}
