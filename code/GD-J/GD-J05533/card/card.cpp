#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int n,m,a[100010],b[100010],d[10010][10010];
int cnt[100010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int m=b[1];
	for(int t=1;t<=n;t++){
		int cnt1=0;//³¡ÉÏÅÆÊý 
		memset(d,0,sizeof(d));
		for(int i=t;i<=n;i++){
			cnt1++;
			d[t][cnt1]=a[i];
			for(int j=1;j<cnt1;j++){
				if(d[t][j]==a[i]){
					cnt1-=i;
					cnt1+=j;
					break;
				}
			}
		}
//		cout<<cnt1<<" ";
//		for(int i=1;i<=cnt1;i++){
//			cout<<d[t][i]<<" ";
//		}
//		cout<<endl;
		for(int i=1;i<=cnt1;i++){
			for(int j=1;j<=m;j++){
				if(d[t][i]==j){
					cnt[j]++;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
