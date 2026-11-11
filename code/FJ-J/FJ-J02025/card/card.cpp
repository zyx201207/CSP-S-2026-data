/*#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int sum[500005];
int now[500005][5],nl;
int n,m;
int main(){
//	freopen("card2.in","r",stdin);
//	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=n;i>=1;i--){
		nl++;
		if(b[a[i]]!=0){
			int cnt9=0;
			nl--;
			while(nl>b[a[i]]){
				cnt9++;
				sum[now[nl][0]]=sum[now[nl][0]]+cnt9;
				b[now[nl][0]]=0;
				nl--;
			}
		}else{
			b[a[i]]=nl;
			now[nl][0]=a[i];
			now[nl][1]=n-i+1;
		}
	}
	for(int i=1;i<=nl;i++){
		sum[now[i][0]]=sum[now[i][0]]+n-now[i][1]+1;
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<' ';
	}
	return 0;
}*/
/*
10 3 
3 1 2 1 3 2 3 1 2 1



*/
#include<bits/stdc++.h>
using namespace std;
int a[500005];

int sum[500005];

int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int l=1;l<=n;l++){
		int b[500005]={0};
		int now[500005]={0},nl=0;
		for(int i=l;i<=n;i++){
			nl++;
			if(b[a[i]]!=0){
				nl--;
				while(nl>b[a[i]]){
					b[now[nl]]=0;
					nl--;
				}
			}else{
				b[a[i]]=nl;
				now[nl]=a[i];
			}
		}
		for(int i=1;i<=nl;i++){
			sum[now[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<' ';
	}
	return 0;
}
/*
10 3 
3 1 2 1 3 2 3 1 2 1



*/
