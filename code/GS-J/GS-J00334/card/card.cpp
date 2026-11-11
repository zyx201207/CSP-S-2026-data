#include<bits/stdc++.h>
using namespace std;
int n,m,cnt=1;
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	int a[n+5],r[m+5],c[m+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		r[i]=0;
		c[i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=0+i;j<=n;j++){
			if(r[cnt-1]==a[j]){
				while(r[cnt-1]==a[j]){
					r[cnt-1]=0;
					cnt--;
				}
			}
			else  {
				r[cnt]=a[j];
				cnt++;
			}
		}
		for(int j=1;j<cnt;j++){
			c[r[j]]+=1;
		}
		cnt=1;
		for(int j=1;j<=m;j++){
			r[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
	return 0;
}
