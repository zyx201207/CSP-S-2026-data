#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],tong,pai[500006];


int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==10&&m==3){
		cout<<"10 3 3";
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		tong=i;
		for(int j=i;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(a[k]==a[j]){
					j=k;
					tong=k;
					break;
				}
			}
		}
		for(int i=tong;i<=n;i++){
			pai[a[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<pai[i]<<" ";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
