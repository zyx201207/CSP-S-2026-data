#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
struct N{
	int flag;
	int whe;
} ton[1000001];
ll n,m,a[1000001],k=1,sum,tong[1000001];
ll card[100001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		k=0;sum=0;
		for(int j=i;j<=n;j++){
			if(ton[a[j]].flag==0){
				ton[a[j]].flag++;
				ton[a[j]].whe=k;
				card[k]=a[j];
				k++;
			}else{
				int k1=ton[a[j]].whe;//k1是哪里开始删（位置），一直删到当前位置
				for(int o=k1;o<=k;o++){
					ton[a[o]].flag=0;
					ton[a[o]].whe=0;
				}
				ton[a[j]].flag++;
				ton[a[j]].whe=k;
				k++;
			}
		}
		for(int j=1;j<=m;j++){
			if(ton[j].flag!=0) tong[j]++;
			ton[j].flag=0;ton[j].whe=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<tong[i]<<" ";
	}
	return 0;
} 
