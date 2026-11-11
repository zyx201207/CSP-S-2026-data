#include<bits/stdc++.h>
using namespace std;
int a[1000000],b[1000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,num=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}

	for(int i=1;i<=n;i++){
			int l=i,l1=l+1;
		while(l1<n){
			if(a[l]==a[l+1]){
				l=l1;
				l1=l+1;
			}else{
				l1++;
			}
		}
		if(i>=l&&i<=l1){
			b[i]=a[i];
			num++;
		}
	}
	for(int i=1;i<=m;i++){
		int cnt=0;
		for(int j=1;j<=num;j++){
				int al=j,al1=j+1;
		while(al1<=num){
			if(b[al]==b[al-1]||b[al]!=i&&al-1>=1){
				break;
			}
			if(b[al1]==b[al]){
				cnt++;
			}
			al1++;
		}
		}
	cout<<cnt<<" ";	
	}
	
	
	
	
	
	
	
}
