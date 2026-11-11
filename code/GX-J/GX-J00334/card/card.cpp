#include<bits/stdc++.h>
using namespace std;
int temp[500005],tn[500005][2];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[500005][2];
	cin>>n>>m;
	for(int i=0;i<n;i++) {
		cin>>a[i][0];
		if(tn[a[i][0]][1]==NULL) tn[a[i][0]][1]=i;
	}	
	for(int i=0;i<n;i++){
		int j=i,te=j-i;
		for(;j<n;j++) {
			temp[te]=a[j][0];
			tn[a[j][0]][0]++;
			if(tn[a[j][0]][0]==2) {
				te=tn[a[j][0]][1]; 
				tn[a[j][0]][0]--;
			}	
			te++;
		}	
		for(te=j-i;te<n;te++) a[temp[te]][1]++;
	}	
	for(int i=0;i<m;i++) cout<<a[i][1]<<' ';
	return 0;
}	
