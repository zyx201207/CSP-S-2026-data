#include<bits/stdc++.h>
using namespace std;
int b[600000];
int c[600000];//b 桶    c 数量 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	int a[500005];//牌的顺序 
	memset(a,0,sizeof(a));
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int max,min;//设置最大和最小，方便后期查找 
	for(int k=1;k<=n;k++){
		max=a[k];
		min=a[k];
		memset(b,0,sizeof(b));
		for(int i=k;i<=n;i++){
			if(b[a[i]]>=1){
				memset(b,0,sizeof(b));
				max=a[i];
				min=a[i];
			}
			b[a[i]]++;
			if(a[i]>max)max=a[i];
			if(a[i]<min)min=a[i];
		}
		for(int i=1;i<=m;i++){
			if(b[i]>=1)c[i]++;
		}	
	}
	for(int i=1;i<=m;i++)cout<<c[i]<<" ";
	return 0;
}
//Trick||Treat!
