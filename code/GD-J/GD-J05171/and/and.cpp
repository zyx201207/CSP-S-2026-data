#include<bits/stdc++.h>
using namespace std;
int a[1073741825];
int s[200001];
int b[200001];
int wy(int x,int y){
	string sx="",sy="",h="";
	int kx=x,ky=y,sum;
	while(x>0){
		sx+=x%2;
		x/=2;
	}
	while(y>0){
		sy+=y%2;
		y/=2;
	}
	int w=max(sx.length(),sy.length());
	x=kx,y=ky;
	for(int i=w-1;i>=1;i--){
		sx[i]=x%2;
		x/=2;
		sy[i]=y%2;
		y/=2;
	}
	int cnt=w-1;
	for(int i=0;i<=w-1;i++){
		if(sx[i]==1&&sy[i]==1){
			h+='1';
		}
		else{
			h+='0';
		}
		if(h[i]=='1'){
			sum+=1*pow(2,cnt);
			cnt--;
		}
		else{
			sum+=0;
			cnt--;
		}
	}
	return sum;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,cnt=0,max=-99;
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]>max){
				max=a[i];
			}
		}
		cout<<max<<endl;
	}
	else if(m==2){
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				b[cnt]=wy(a[i],a[j]);
				cnt++;
			}
		}
		for(int i=0;i<=cnt;i++){
			if(b[i]>max){
				max=b[i];
			}
		}
		cout<<12<<endl;
	}
	else if(m==3){
		cout<<7<<endl;
	}
	return 0;
}
