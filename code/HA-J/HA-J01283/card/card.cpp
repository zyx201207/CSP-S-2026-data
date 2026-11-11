#include<bits/stdc++.h>
using namespace std;
int n,m,a[300005],card[500005],desk[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>card[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			bool flag=0;
			int k=1;
			while(desk[k]!=0){
				if(desk[k]==card[j]){
					flag=1;
					break;
				}else{
					k++;
				}
			}
			if(flag==1){
				int i_=k;
				while(desk[i_]!=0){
					desk[i_]=0;
					i_++;
				}
			}
			desk[k]=card[j];
		}
		int j_=1;
		while(desk[j_]!=0){
			a[desk[j_]]++;
			desk[j_]=0;
			j_++; 
		}
	}
	for(int i=1;i<=m;i++)
		cout<<a[i]<<' ';
	return 0;
}

