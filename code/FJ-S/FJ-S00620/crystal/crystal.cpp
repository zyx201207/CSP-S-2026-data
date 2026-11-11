#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500050][2],n,m,c1/* 最大*/,c2,c3,c4,c5,c6,c7,c8,d1,d2;
/*int dfs(int a){
	a--;
	for(int i=1;i<=n)
}
*/
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>c1;
		d2=d1;
		for(ll j=1;j<=d2+1;j++){
			if(a[j][1]==c1){
				a[j][2]=a[j][2]+1;
				break;
			}
			if(j==(d2+1)){
				d1++;
				a[d1][1]=c1;
				a[d1][2]=a[d1][2]+1;
			}
		}

	}
	
//		for(ll i=1;i<=d1;i++){
//		cout<<a[i][1]<<":"<<a[i][2]<<endl;
//	}

	
	for(ll j=1;j<=d1-1;j++){
	
		for(ll i=1;i<=d1-1;i++){
			if(a[i][1]>a[i+1][1]){
				c1=a[i+1][1];
				c2=a[i+1][2];
				a[i+1][1]=a[i][1];
				a[i+1][2]=a[i][2];
				a[i][1]=c1;
				a[i][2]=c2;
			}
		}
	}
	
	
//	for(ll i=1;i<=d1;i++){
//		cout<<a[i][1]<<":"<<a[i][2]<<endl;
//	}
	
	a[d1+1][1]=0x3f3f3f3f3f3f3f3f;
	for(ll i=d1;i>=1;i--){
		c2=m;
		c3=i-1;
		c5=i+1;
		while(c2>0){
			if((a[i][1]-a[c3][1])<=(a[c5][1]-a[i][1])){
				c2=c2-(a[i][1]-a[c3][1])*a[c3][2];
				if(c2>=0){
					c4+=a[c3][2];
				}
				if(c2<0){
					c2+=(a[i][1]-a[c3][1])*a[c3][2];
					c4+=c2/(a[i][1]-a[c3][1]);
					break;
				}
				if(c3==0){
					break;
				}
				c3--;
			}else{
				c2=c2-(a[c5][1]-a[i][1])*a[c5][2];
				if(c2>=0){
					c4+=a[c5][2];
				}
				if(c2<0){
					c2+=(a[c5][1]-a[i][1])*a[c5][2];
					c4+=c2/(a[c5][1]-a[i][1]);
					break;
				}
				if(c5>=d1){
					c5--;
				}
				c5++;

		}
		c1=max(c4,c1);
		c4=0;
	}
	}
	cout<<c1;
	
	return 0;
}
/*
5 8
-3 -1 2 2 7
5 5
1 2 4 8 9

*/