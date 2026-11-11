#include<bits/stdc++.h>
using namespace std;
long long i,j,k,n,m,bs,cd[200010],h,zd=-1,ma=-1,q,bl,tc=0;
char l[200010][35];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++,bs=1){
		cin>>k;
		if(k>ma) ma=k;
		if(k==0){
			l[i][1]='0';
		}else{
			while(k>0){
				l[i][bs]=k%2+'0';
				k/=2;bs++;
			}cd[i]=bs-1;
		}
	}if(m==1){
		zd=ma;
	}else if(m==2){
		for(i=1;i<n;i++){
			for(j=i+1;j<=n;j++){
				for(k=1,h=0,bs=1;k<=min(cd[i],cd[j]);k++,bs*=2){
					if(l[i][k]=='1'&&l[j][k]=='1'){
						h+=bs;
					}
				}if(zd<h){
					zd=h;
				}
			}
		}
	}else if(m==n){
		bl=0;
		for(i=1,bs=1;i<=m&&tc==0;i++,bl=0,bs*=2){
			for(j=1;j<=m;j++){
				if(cd[j]>=i){
					tc=1;break;
				}else if(l[j][i]=='0'){
					bl=1;break;
				}
			}if(bl==0){
				zd+=bs;
			}
		}
	}else{
		for(i=1;i<n;i++){
			for(j=i+1;j<=n;j++){
				for(q=j+1;q<=n;q++){
					for(k=1,h=0,bs=1;k<=min(min(cd[i],cd[j]),min(cd[j],cd[q]));k++,bs*=2){
						if(l[i][k]=='1'&&l[j][k]=='1'&&l[q][k]=='1'){
							h+=bs;
						}
					}if(zd<h){
						zd=h;
					}
				}
			}
		}
	}
	cout<<zd;
	return 0;
}
