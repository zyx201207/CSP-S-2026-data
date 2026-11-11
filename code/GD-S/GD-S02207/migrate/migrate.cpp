#include<bits/stdc++.h> 
using namespace std;
int c,t,n,d;
int x[100005],a[100005];
int sw,ew;
int k;
void yue(int wz,int m){
	if(wz>ew)return;
	if(wz==ew){
		a[m]++;
		return;
	}
	int i=wz+1;
	while(x[wz]+d>x[i]){
		yue(i,m+1);
		i++;
		if(i>ew)return ;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		k=0;
		for(int j=1;j<=n;j++){
			sw=j;
			for(int l=j+2;l<=n;l++){
				ew=l;
				yue(sw,1);
				for(int s=1;s<=n;s++){
					if(a[s]>0){
						if(a[s]==2){
							k++;
						}
						break;
					}
				}
				for(int s=1;s<=n;s++)a[s]=0;
			}
		}
		cout<<k<<' ';
	}
	return 0;
}
