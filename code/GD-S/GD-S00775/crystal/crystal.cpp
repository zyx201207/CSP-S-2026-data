#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],l=1,sy,dqsl,zz=-114514,dc;
bool pd=1,pdb=1;
void speca(){
	for(int i=1;i<=n;i++){
		if(m-i>=0){
			m=m-i;
			zz++;
		}
		else
			break;
	}
	return ;
}
void specb(){
	dc=a[2]-a[1];
	for(int i=1;i<=n;i++){
		if(m-i*dc>=0){
			m=m-i*dc;
			zz++;
		}
		else
			break;
	}
	return ;
}
int main(){
	//二分？？前缀和？？ 
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	a[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]-a[i-1]!=1){
			pd=false;
		}
		if(i>1){
			if(a[i]-a[i-1]!=a[2]-a[1]){
				pdb=false;
			}
		}
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	sort(a+1,a+1+n);
	if(pd){
		zz=0;
		speca();
		if(zz==n){
			zz=n-1;
		}
		cout<<zz+1;
		return 0;
	}
	if(pdb){
		zz=0;
		specb();
		if(zz==n){
			zz=n-1;
		}
		cout<<zz+1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		dqsl=0;
		for(int j=i;j<=n;j++){
			sy=(a[j+1]-a[j])*j;
			if(a[j+1]==a[j])
				dqsl++;
			if(a[j+1]>a[j]&&sy<=m){
				dqsl++;
				m=m-sy;
			}	
		}
		zz=max(dqsl,zz);
	}
	cout<<zz+1;
	return 0;
} 
