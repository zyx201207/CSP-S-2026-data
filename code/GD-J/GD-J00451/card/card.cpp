#include <bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[500010],s[300010],c=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	//局数 
	for(int i=1;i<=n;i++){
		//打牌 
		for(int j=i;j<=n;j++){
			//查找是否有牌与之对应 
			for(int k=1;k<=c;k++){
				if(a[j]==b[k]){
					//删除 
					for(int z=k;z<=c;z++){
						b[z]=0;
					}
					c=k-1;
					break;
				}
			}
			b[++c]=a[j];
		}
		for(int j=1;j<=c;j++){
			s[b[j]]++;
		}
		c=1;
		for(int j=0;j<500010;j++){
			b[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}
