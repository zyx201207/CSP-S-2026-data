#include<iostream>
using namespace std;

int n,m;
int mc[2000005];
int mf[2000005][2];
int a[2000005];
int zm[2000005];

int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int p=0;
		for(int j=1;j<=m;j++){
			mf[j][0]=0;
			mf[j][1]=0;
			zm[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(mf[a[j]][0]==0){
				zm[++p]=a[j];
				mf[a[j]][0]=1;
				mf[a[j]][1]=p;
			}
			else {
				int s=p;
				for(int k=mf[a[j]][1];k<=s;k++){
					mf[zm[p]][1]=0;
					mf[zm[p]][0]=0;
					zm[p]=0;
					p--;
				}
				zm[++p]=a[j];
				mf[a[j]][0]=1;
				mf[a[j]][1]=p;
			}
		}
		for(int j=1;j<=p;j++){
			mc[zm[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<mc[i]<<' ';
	}
	return 0;
}
