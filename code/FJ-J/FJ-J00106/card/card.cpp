#include<bits/stdc++.h>
using namespace std;
const int N=500010;
const int M=300010;
int a[N];
int ans[M];
int b[M];//Î»ÖÃ 
int c[M],r;//ÅÆ¶Ñ
int rd(){
	int o=0;
	char a;
	a=getchar();
	while('0'<=a&&'9'>=a){
		o=o*10+(a-'0');
		a=getchar();
	}
	return o;
}
void pt(int o){
	if(o<10){
		putchar(o+'0');
		return;
	}
	pt(o/10);
	putchar(o%10+'0');
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	n=rd();;
	m=rd();
	for(int i=0;i<n;i++){
		a[i]=rd();
	}
	for(int i=0;i<n;i++){
		r=0; 
		for(int j=i;j<n;j++){
			if(c[b[a[j]]]==a[j]&&b[a[j]]<r){//ÔÚÅÆ¶ÑÀï
				r=b[a[j]]+1; 
			}
			else{
				c[r]=a[j];
				b[a[j]]=r;
				r++; 
			}
		}
		for(int j=1;j<=m;j++){
			if(c[b[j]]==j&&b[j]<r){
				ans[j]++; 
			}
		}
	}
	for(int i=1;i<=m;i++){
		pt(ans[i]);
		putchar(' ');
	}
	return 0;
}
