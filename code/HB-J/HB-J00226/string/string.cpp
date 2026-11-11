#include<bits/stdc++.h>
using namespace std;
int a[100001];
char p[100001];
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n,k=0;
scanf("%d",&n);
int l=0,g=0;
for(int i=1;i<=n;i++){
	scanf("%d %c",&a[i],&p[i]);
	l+=a[i];
	}
	bool o=l%2==0?1:0;
	l/=2;
	int h=0;
	for(int i=1;i<=n;i++){
	g+=i;
	if(g>=l){
		h=i;
		break;
		}
	}
	if(a[h]>l){
		if(o){a[h]=a[h]-2*(a[h]-l);}else{a[h]=a[h]-2*(a[h]-l)-1;}
		if(a[h]<0){
			h-=1;
			a[h]=abs(a[h]);
			}
		}
		for(int i=1;i<=h;i++){
			for(int j=n;j>h;j--){
			if(p[i]!=p[j]){
			if(a[i]>a[j]){
				a[i]-=a[j];
				
				}else{
				a[j]-=a[i];
				break;
			}
			k+=min(a[i],a[j]);
			}
			}
		}
		printf("%d",k);
fclose(stdin);
fclose(stdout);
return 0;
}
