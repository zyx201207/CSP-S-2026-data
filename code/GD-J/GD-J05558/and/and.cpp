#include<bits/stdc++.h>
using namespace std;
string x,y,z;
int a[200010],b[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ma1=-1,id=0,ma2=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(ma1<a[i]){
			ma1=a[i];
			id=i;
		}
	}
	b[id]=1;
	m--;
	while(m--){
		ma2=0;
		for(int i=1;i<=n;i++){
			if(a[i]>ma2&&b[i]==0){
				ma2=a[i];
				id=i;
			}
		}
		b[id]+=1;
		int h=ma1,g=ma2;
		x={};
		y={};
		while(h){
			x+=h%2+'0';
			h/=2;
		}while(g){
			y+=g%2+'0';
			g/=2;
		}
		for(int i=0;i<max(x.size(),y.size());i++){
			if(x[i]=='1'&&y[i]=='1'){
				z+='1';
			}else{
				z+='0';
			}
		}
		ma1=0;
		
		for(int i=z.size()-1;i>=0;i--){
			if(z[i]=='1')
			ma1+=pow(2,i);
		}
		z={};
	}
	cout<<ma1;
	return 0;
}

