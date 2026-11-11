#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card,in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[500005],table[500005],tail=0,num[300005],b=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int z=1;z<=tail;z++){
				if(a[j]==table[z]){
					tail==z;
					b=1;
					break;
				}
			}
			if(b==0){
				tail++; 
				table[tail]=a[j];
			}
		}
		for(int x=1;x<=m;x++){
			if(table[x]==m){
				num[x]++; 
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<num[i];
	}
	return 0;
}
