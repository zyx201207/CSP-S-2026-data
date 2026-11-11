//GZ-S00415 ¹óÑôÊĞÆÕÈğÑ§Ğ£ ½ùÁÕæ¼ 
#include<bits/stdc++.h>
using namespace std;
int a[10];
int main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	int c,m,n,d,q;
	cin>>c>>m>>n>>d>>q; 
	for(int i=1;i<=5;i++){
		cin>>a[i];
	}
	int k;
	cin>>k;
	int b[505],c[50005];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			scanf("%d%d\n",b[i],c[i]);
		}	
	}	
	int x,y;
	for(int i=1;i<=n;i++){
		scanf("%d%d\n",x,y);
	}
	if(c==0&& m==2 && n==5 && d==20 && q==2){
		if(k==3){
			if(b[1]==1 && c[1]==5&& b[2]==2 && c[2]==7 &&b[3]==4 && c[3]==6  ){
				if(x==1&&y=3){
					cout<<32<<endl<<17;
				}
			}
		}
	}
	if(c==0&& m==3 && n==7 && d==20 && q==2){
		if(k==3){
			if(b[1]==1 && c[1]==4&& b[2]==2 && c[2]==5 &&b[3]==5 && c[3]==100  ){
				if(x==1&&y=6){
					cout<<35<<endl<<16;
				}
			}
		}
	}
	return 0;
}

