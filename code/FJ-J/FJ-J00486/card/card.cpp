#include<bits/stdc++.h> 
using namespace std;

int n,m,a[300500],b[300500],c[300500],d[300500];//Cici

void bl(){
	for(int i=0;i<300500;i++){
		b[i]=0;
	}
	return ;
}
void cl(int t,int j){
	for(int i=j-1;i>=0;i--){
		if(c[i]==t){
			c[i]=0;
			return ;
		}
		c[i]=0;
	}
	return ;
}
void cc(){
	for(int i=0;i<300500;i++){
		c[i]=0;
	}
	return ;
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);//Oldbig
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			c[j]=a[j];
			b[a[j]]++;
			if(b[a[j]]>1){
				cl(a[j],j);
				bl();
				for(int k=0;k<n;k++){
					b[c[k]]++;
				}
			}
		}
		for(int j=0;j<300500;j++){
			if(c[j]){
				d[c[j]]++;
			}
		}
		bl();
		cc();
	}
	for(int i=1;i<=m;i++){
		printf("%d ",d[i]);
	}
	return 0;
}
