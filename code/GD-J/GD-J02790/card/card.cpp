#include <bits/stdc++.h>
using namespace std;
long long n,m,a[100005],b[100005],zm[100005],z=0,i1=1,temp=0,jg[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=1;i<=n;i++){//每局游戏 
		for(int j=1;j<=z;i++){
			zm[j]=0;
		}
		i1++;
		z=0;
		for(int j=1;j<=n;j++){
			a[j]=b[j];
		}
		for(int j=i1;j<=n;j++){//每次抽牌 
			for(int k=1;k<=z;k++){//看每张牌 
				if(zm[k]==a[j]){
					temp=0;
					for(int w=k;w<=z;w++){
						a[w]=0;
					}
					zm[k]=a[j];
					break;
				}
			}
		}
		for(int j=1;j<=z;j++){
			jg[zm[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<jg[m]<<" ";
	}
	return 0;
}

