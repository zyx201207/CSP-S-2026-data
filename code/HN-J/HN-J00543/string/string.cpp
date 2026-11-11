#include<bits/stdc++.h>
using namespace std;
struct s{
	long long gs;
	char zf;
};
s a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long m=0,jg=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].gs);
		scanf(" %c",&a[i].zf);
		m+=a[i].gs;
	}
	long long k=m/2,j=0,c=0;
	while(k>=0){
		k-=a[++j].gs;
	}
	j--;
	int b=n;
	for(int i=1;i<=j;){
		if(a[i].gs>=a[b].gs){
			a[i].gs-=a[b].gs;
			c-=a[b].gs;
			if(a[i].zf!=a[b].zf){
				jg+=a[b].gs;
			}
			if(a[i].gs==0) i++;
			b--; 
		}else{
			a[b].gs-=a[i].gs;
			c-=a[i].gs;
			if(a[b].zf!=a[i].zf){
				jg+=a[i].gs;
			}
			i++; 
		}
	}
	cout<<jg;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
