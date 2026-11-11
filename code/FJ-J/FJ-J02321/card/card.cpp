#include<iostream>
#include<cstdio>
using namespace std;
int P[500001], pn[300001];
int main(){
	int n, m, a[500001];
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int p=0;
		for(int j=i;j<n;j++){
			for(int k=0;k<p;k++){
				if(a[j]==P[k]){
					for(int r=k;r<p;r++){
						P[r]=0;
					}
					p=k;
					break;
				}
			}
			P[p]=a[j];
			p++;
		}
		for(int j=1;j<=m;j++){
			for(int k=0;k<p;k++){
				if(P[k]==j){
					pn[j-1]++;
				}
			}
		}
		for(int j=0;j<p;j++){
			P[j]=0;
		}
	}
	for(int i=0;i<m;i++){
		cout<<pn[i]<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
