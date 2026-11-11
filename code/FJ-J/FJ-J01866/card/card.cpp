#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[300005];
int c[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out ","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	} 
	for(int k = 1;k <= n;k++){
		int index=0;
		for(int i = k;i <= n;i++){
			bool flag = false;
			int x = index;
			for(int j = 1;j <= index;j++){
				if(flag){
					c[j]=0;
					continue;
				}
				if(c[j]==a[i]){
					x=j-1;
					flag = true;
					c[j]=0;	
				}
			}
			index++;
			c[index]=a[i];
			
		}
		for(int j = 1;j <= index;j++){
			b[c[j]]++;
		}
	}
	
	for(int i = 1;i <= m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
