#include<iostream>
using namespace std;
int n,m,a[1000001],sum[1000001],q[100001];
bool card[1000001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1,x=0;i<=n;i++,x=0){
		for(int j=1;j<=m;j++){
			card[j]=0;
		}
		for(int j=i;j<=n;j++){
			int c=a[j];
			if(card[c]!=1){
				q[++x]=c;
				card[c]=1;
			}
			
			else{
				for(;q[x]!=c;x--){
					card[q[x]]=0;
					q[x]=0;
				}
			}
			/*
			for(int j=1;j<=x;j++){
				cout<<q[j]<<" ";
			}
			cout<<endl;*/
		}
		for(int j=1;j<=x;j++){
			sum[q[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
} 
