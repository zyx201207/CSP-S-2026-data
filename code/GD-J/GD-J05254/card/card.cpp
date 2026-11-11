#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,m1=0,m2=0,m3=0;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<m;i++){
		int len=0;
		cin>>a[i];	
		for(int j=i;j<n;j++){
			
			for(int t=0;t<j;t++){
				len++;
				if(a[t]==a[j]){
					for(int k=t;k<j;k++){
						a[t]=a[j];
						len--;
					}
					t=j;
				}
			}
		}
		for(int i=0;i<len;i++){
			if(a[i]==1){
				m1++;
			}
			if(a[i]==2){
				m2++;
			}
			if(a[i]==3){
				m3++;
			}
		}
	}
	cout<<m1<<m2<<m3;
	return 0;
}
