#include <bits/stdc++.h>
using namespace std;
int a[114514],b[114514],c[114514];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		int py[114514]={0};
		for (int j=1;j<=n;j++){
			if (py[a[j]]==0){
				py[a[j]]=j;
				b[j]=a[j];
			}
			else{
				for (int z=py[a[j]];z<=j;z++){
					b[z]=0;
				}
			}
		}
	}
	return 0;
} 
