//GZ-J00616 观山湖中学 张皓宇 
#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005];
int main(){
	freopen("card.in",r,stdin);
	freopen("card.out",w,stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		b[i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int x;
			bool f=true;
			c[j]=a[j];
			for(int k=1;k<=n;k++){
				if(c[j]==c[k]){
					f=false;
					x=k;
					break;
				}
			}
			if(f==false){
				for(int k=1;k<=x-1;k++){
					c[k]=0;
				}
			}
		}
		for(int j=1;j<=n;j++){
			while(c[j]--){
				b[j]++;
			}
		}
	}
	return 0;
} 
