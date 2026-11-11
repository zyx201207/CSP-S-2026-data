#include <bits/stdc++.h>
using namespace std;
int a[500100];
int b[300100];
int c[500100];
int d[300100];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,cx;
	cin >>n>>m;
	for(int i=1  ;i<=n ; i++){
		cin >>a[i];
	}
	for(int i=1 ; i<=n ; i++){
		cx=1;
		for(int j=1 ; j<=n ; j++){
			c[j]=0;
		}
		for(int j=1 ; j<=m ; j++){
			d[j]=0;
		}
		for(int j=i ; j<=n ; j++){
			if(d[a[j]]==0){
				d[a[j]]++;
				c[cx]=a[j];
				cx++;
			}else{
				int w=0,cy=0;
				for(int k=1 ; k<=cx ; k++){
					if(w){
						d[c[k]]=0;	
						c[k]=0;
					}
					if(c[k]==a[j]){
						w=1;
						cy=k;
					}
				}
				cx=cy+1;
			}
		}
		for(int j=1 ; j<=cx ; j++){
			b[c[j]]++;
		}
	}
	for(int i=1 ; i<=m ; i++){
		cout <<b[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
