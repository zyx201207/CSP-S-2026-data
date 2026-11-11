#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x,y;
int cnt=0;
int s[2000005];
void fin(int x,int y){
	for(int j=y+1;j<=n;j++){
		if(s[x]+d-s[j]>=0&&s[y]+d-s[j]>=0){
			cnt++;
			return;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>s[j];
		}
		for(int j=1;j<=n;j++){
			int ww=0;
			for(int w=j+1;w<=n;w++){
				if(s[j]+d-s[w]>=0){
					ww++;
					if(x==0){
						x=w;
					}
					else{
						y=w;
					}
					if(ww>2){
						break;
					} 
				}
			}
			if(ww==2){
				fin(x,y);
			}
			if(ww>2){
				continue;
			}
		}
		cout<<cnt<<"\n";
		
	}
	
	
	return 0;
} 
