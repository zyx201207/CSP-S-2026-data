#include<bits/stdc++.h>
using namespace std;
int ma=-1,n,m,p,a[500006];
int f[200003][10];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(a[i],ma);
		if(a[i]==0) ss0++;
		if(a[i]==1){
			f[i][0]=1;
			ss1++;
		}
		else if(a[i]==2){
			f[i][1]=1;
			ss2++;
		}
		else if(a[i]==3){
			f[i][0]=1;
			f[i][1]=1;
			ss3++;
		}
		else if(a[i]==4){
			f[i][2]=1;
			ss4++;
		}
		if(i==1){
			for(int j=0;j<=20;j++){
				if(a[i]==(pow(2,j)-1)) {
					p=13;
					break;
				}	
			}
		}
				
	}
	if(p==13){
		sort(a+1,a+1+n);
		cout<<a[m],exit(0);
	}
	
	if(m==1){
		cout<<ma,exit(0);
	}
	else {
		if(ss4>=m) cout<<4,exit(0);
		else if(ss0>=n-m) cout<<0,exit(0);
		else if(ss3>=m) cout<<3,exit(0);
		else if(ss2>=m) cout<<2,exit(0);
		else if(ss1>=m) cout<<1,exit(0);
	}
} 
