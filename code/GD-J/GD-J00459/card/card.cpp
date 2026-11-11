
#include<bits/stdc++.h>
using namespace std;
struct h{
	int x;
	int o;
};
int a[5000005],c[10000010];
h b[10000010];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdin);
	cin.tie(0);
	long long n,m;
	cin>>n>>m;
	int True[m+1]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int k=1;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			b[k].x=a[j];
			
			if(c[b[k].x]==0){
				c[b[k].x]=b[k].x;
			}
			if(c[b[k].x]!=0){
				for(int u=1;u<i;u++){
					b[u].x=0;
				}
			}
			k++;
		}
		for(int j=1;j<=m;j++){
			for(int u=1;i<=k;i++){
				if(b[u].x==j){
					True[j]++;
				}
			}
			cout<<True[j]<<" ";
		}
		//b[k].o=i;
		
	}
	/*
	for(int i=1;i<=k;i++){
		cout<<b[i].x<<" ";
	}
	cout<<endl;
	for(int i=1;i<=k;i++){
		if(c[b[i].x]==0){
			c[b[i].x]=b[i].x;
		}
		if(c[b[i].x]!=0){
			for(int j=1;j<i;j++){
				b[j].x=0;
			}
		}
	}
	for(int i=1;i<=k;i++){
		cout<<b[i].x<<" ";
	}
	cout<<endl;
	for(int j=1;j<=m;j++){
		int sum=0;
		for(int i=1;i<=k;i++){
			if(b[i].x==j){
				sum++;
			}
		}
		cout<<sum<<" ";
	}*/
	return 0;
} 

