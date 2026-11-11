#include<bits/stdc++.h>
using namespace std;
int a[100001];
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int n,m,o=-1,l;
scanf("%d %d",&n,&m);
for(int i=1;i<=n;i++){
	scanf("%d",&a[i]);
	o=max(a[i],o);
	}
	l=a[1];
	for(int i=2;i<=n;i++){
	l&=a[i];
	}
	if(m==1){
		printf("%d",o);
		}else{
		printf("%d",l);	
			}
fclose(stdin);
fclose(stdout);
return 0;
}
