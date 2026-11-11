#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m,count;
	cin>>n>>m;
	int a[n]={0};//原有牌组 
	int b[n]={0};//牌桌上的牌 
	int c[m]={0};//出现次数 
	int d[m]={0};//每局牌的位置 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		count=0;
		for(int j=i;j<=n;j++){
			if(d[a[j]]==0){
				b[count]=a[j-1];
				d[a[j]]=count;
			}else{
				for(int x=d[a[j]];x<n;x++){
					if(d[b[x]]!=0){
						d[b[x]]=x;
					}
					b[x]=0;
				}
				count=d[a[j]]+1;
			}
		}
		for(int j=1;j<n+1;j++){
			c[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
}
