#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool b[200005];
bool x[31]={},y[31]={},re[31]={};
int n,m,ma=-1;
int man(int w,int z){
	if(w==3&&z==15||w==15&&z==3){
		return 3;
	}
	if(w==1||w==3||w==7||w==15||w==31){
		return z;
	}
	if(z==1||z==3||z==7||z==15||z==31){
		return w;
	}
	bool o=1;int ix=0;int s=0;
	while(o!=0){
		ix++;
		if(w==1){
			o=0;
		}
		x[ix]=w%2;
		w=w/2;
	}
	o=1;int iy=0;
	while(o!=0){
		iy++;
		if(z==1){
			o=0;
		}
		y[iy]=z%2;
		z=z/2;
	}
	for(int i=1;i<=max(ix,iy);i++){
		if(x[i]&&y[i]){
			re[i]=1;
		}
		else{
			re[i]=0;
		}
	}
	for(int i=max(ix,iy);i>=1;i--){
		s+=pow(2,i-1)*re[i];
	}
	return s;
}
void find(int s,int x){
	if(x==m+1){
		if(ma<s){
			ma=s;
		}
	}
	else{
		for(int i=1;i<=n;i++){
			if(b[i]!=1){
				int d=s;
				if(s==-1){
				//cout<<"s从"<<s;
					s=a[i];
				//cout<<"变为"<<s<<','<<x<<endl; 
				}
				else{
					//cout<<s<<' '<<a[i]<<"s从"<<s;
					s=man(s,a[i]);
					//cout<<"变为"<<s<<','<<x<<endl; 
				}
				b[i]=1;
				x++;
				find(s,x);
				b[i]=0;
				x--;s=d;
			}
		} 
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=0;
	}
	find(-1,1);
	cout<<ma<<endl;//cout<<man(2,31);
	return 0;
}
/*
4 2
3 15 12 12
*/
