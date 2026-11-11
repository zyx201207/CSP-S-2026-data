#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200002],f=1,s;
void andd(int nu,int l,int vis){
	if(vis==m||l==n-1){
		if(nu>s&&vis==m) s=nu;
	}
	else{
		andd(nu&a[l],l+1,vis+1);
		andd(nu,l+1,vis);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>=4) f=0;
	}
	if(m==1){
		for(int i=0;i<n;i++){
			s=max(a[i],s);
		}
	}
	else if(m==n){
		s=a[0];
		for(int i=1;i<n;i++) s&=a[i];
	}
	else if(m==2){
		s=-999;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i!=j) s=max(a[i]&a[j],s);
			}
		}
	}
	else if(f){
		int w,x,y,z;
		for(int i=0;i<n;i++){
			if(a[i]==0) w++;
			if(a[i]==1) x++;
			if(a[i]==2) y++;
			if(a[i]==3) z++;
		}
		if(z>=m) s=3;
		else if(z+y>=m) s=2;
		else if(z+x>=m) s=1;
		else s=0;
	}
	else if(n<=20){
		s=-999;
		andd(a[0],0,1);
		andd(a[1],0,0);
	}
	else{
		s=999999999;
		for(int i=0;i<n;i++){
			s=min(a[i],s);
		}
	}
	cout<<s;
	return 0;
}
