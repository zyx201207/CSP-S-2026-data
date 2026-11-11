#include<bits/stdc++.h>
using namespace std;
const int N=6000;
int a[N],b[N],c[N],q[N],t[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n=0,m=0,cnt=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0){
				q[a[j]]=cnt;
				c[cnt++]=a[j];
				b[a[j]]++;}
			else{
				for(int k=q[a[j]];k<=cnt;k++){
					b[c[k]]=0;

					c[k]=0;
					cnt--;
					
				}
				c[cnt++]=a[j];
			}
		}
		for(int i=1;i<=cnt;i++) q[c[cnt]]++;
		
	}
	for(int i=1;i<=m;i++) cout<<t[i]<<" ";
} 
