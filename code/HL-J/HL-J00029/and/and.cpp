#include<bits/stdc++.h>
using namespace std;
int n,m,mj,jm=1,hhh[30],da[30],kk,ma;
struct ff{
	int a[25];
	int h=0;
}f[200005];
int d=1;
bool hh(ff s,ff k){
	if(s.h>k.h){
		return 1;
	}
	return 0;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>mj;
		while(mj>=jm){
			d=++f[i].h;
			jm*=2;
		}
		if(d>ma){
			ma=d;
		}
		hhh[d]++;       
		jm=1;      
		while(mj){
			f[i].a[d--]=mj%2;
			mj/=2;
		}     
		d=1;   
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=f[i].h;j++){
			cout<<f[i].a[j];
		}
		cout<<endl;
	}
	for(int i=1;i<=ma;i++){
	sort(f+1,f+n+1,hh);
	if(hhh[f[1].h]>=m){
		for(int i=1;i<=n;i++){
			if(f[i].h!=f[1].h){
				n=i-1;
				da[++kk]=1;
				cout<<da[kk];
				break;
			}
		}
	}else{ 
		cout<<0;
		for(int i=2;i<=n;i++){
			if(f[i].h==f[1].h){
				for(int u=1;;u++){
				f[i].h--;
				for(int j=f[i].h;j>=1;j--){
					f[i].a[j]=f[i].a[j+1];
				}
				if(f[i].a[1]!=0||f[i].h==1){
					break;
				}
				}
			}else{
				for(int u=1;;u++){
				f[1].h--;
				for(int j=f[1].h;j>=1;j--){
					f[1].a[j]=f[1].a[j+1];
				}
				if(f[1].a[1]!=0||f[1].h==1){
					break;
				}
				}
			}
		}
	}
	}
	cout<<kk;
		for(int j=1;j<=kk;j++){
			cout<<da[j];
		}
		cout<<endl;
	return 0;
}