#include<bits/stdc++.h>
using namespace std;
int n,m;
int  a[500005],c[300005],t[500005];
bool x[500005],xx[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]==a[j]) t[j]=i;
		} 
	}
	//暴力枚举
	int start=1;
	while(start<=n){
		for(int i=1;i<=start;i++) x[i]=false,xx[i]=false;
		for(int i=start;i<=n;i++) x[i]=true,xx[i]=false;//初始化 
		
		for(int i=start;i<=n;i++){//加一张牌 
			int bqb=i;
			while(t[bqb]!=0 && t[bqb]>=start && x[t[bqb]]==true) bqb=t[bqb];
			for(int k=bqb;k<i;k++) x[k]=false;
		
		
		}
		
		
		for(int i=start;i<=n;i++)
			if(x[i]) xx[a[i]]=true;
		
		
		for(int i=1;i<=m;i++)
			c[i]+=xx[i];
		
	
		start++;
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
