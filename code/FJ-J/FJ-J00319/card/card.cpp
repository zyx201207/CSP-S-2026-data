#include<bits/stdc++.h>
using namespace std;
int a[500001],t[500001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	int n,m,flag=0,flug=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int r[500001];
		for(int j=i;j<=n;j++){
			int fleg=0;
			for(int k=1;k<=flag;k++){
				if(r[k]==a[j]){
					fleg++;
					flug=k;
					break;
				}
			}
			if(fleg==1){
				for(int k=flug;k<=flag;k++)r[k]=0;
				flag=flug;
				flug=0;
			}
			flag++;
			r[flag]=a[j];
		}
		for(int j=1;j<=flag;j++){
			t[r[j]]++;
		}
		memset(r,0,flag);
		flag=0;
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
}
