#include<bits/stdc++.h>
using namespace std;
int a[200001]={},n,x1=0,y1=1,x2=0,y2=0,z=0;
long long sn=0,s=0;
char c[200001]={};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	x2=n-1;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);

scanf("%s",&c[i]);		
		sn=sn+a[i];
	}
	y2=a[x2];
	//printf("%d %d %d %d %d %d\n",x1,y1,x2,y2,s,z);
	while (1){//for(int i=0;i<sn/2;){
		//y1++;
		//y2--;
		if(x1==x2){
			break;
		}
		if(y1>a[x1]){
			y1=1;
			x1=x1+1;
		}
		if(y2<=0){
			y2=a[x2-1];
			x2=x2-1; 
		}
		z=min(a[x1]-y1+1,y2);
		if(c[x1]==c[x2]){
			y1+=z;
			y2-=z;
		}
		else{
			y1+=z;
			y2-=z;
			s+=z;
		}
		//printf("%d %d %d %d %d %d ",x1,y1,x2,y2,s,z);
		//cout<<c[x1]<<c[x2]<<'\n';
	}
	printf("%lld",s);
	return 0;
}
