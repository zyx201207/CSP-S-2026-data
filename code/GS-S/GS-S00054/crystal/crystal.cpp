#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[5*10^5+1], biao[2], b[5*10^5+1];
int go(int i, int n, int bao1, int bao2, int l){
	l++;
	if(i<=l){
		return bao2;
	}
	int d[5*10^5+1];
	for(int i=1;i<=n;i++){
		cin>>d[i];
		
	}
	for(int j=1;j<=n;j++){
		d[j]++;
	
		for(int bia=1;bia<=n;bia++){					 
			for(int bi=1;bi<=bia;bi++){
				if(d[bia]==d[bi]){
					bao1++;
				}						
			}
			if(bao1>bao2){
					bao2=bao1;	
			}
			bao1=0;
		}
	
		bao1=go(i, n, bao1, bao2, l);
		if(bao1>bao2){
			bao2=bao1;
		}
	}
	return bao2;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin>>n>>m;
	
	biao[1]=0;
	for(int j=1;j<=n;j++){
			b[j]=a[j];
		}
	for(int i=0;i<=m;i++){
		
		
		biao[0]=go(i, n, biao[1], biao[2], 1); 
		if(biao[2]>biao[0]){
			biao[0]=biao[2];
		}
	}
	cout<<biao[0];
	return 0;
} 
