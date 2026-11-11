#include<bits/stdc++.h>
using namespace std;
long long n;
long long ans=0;
struct zifuchuan{
	long long daxiao;
	char zifu;
};
zifuchuan a[200100];
void shuru(){
	scanf("%lld",&n);
	char aaa;
	for(int i=0;i<n;i++){
//		printf("i=%d",i);
		scanf("%lld",&a[i].daxiao);
		scanf("%c",&aaa);
		scanf("%c",&a[i].zifu);
	}
//	printf("aaa");
}
void jisuan(){
	long long bia=a[0].daxiao;
	long long bib=a[n-1].daxiao;
	for(int i=0,o=n-1;i<o;){
//		printf("bia=%lld,bib=%lld\n",bia,bib);
//		printf("zifua=%c,zifub=%c",a[i].zifu,a[o].zifu);
		if(bia==0){
			i++;
			bia=a[i].daxiao;
		}else if(bib==0){
			o--;
			bib=a[o].daxiao;
		}
		if(bia>=bib){
			if(a[i].zifu!=a[o].zifu){
				ans+=bib;
			}
			bia-=bib;
			bib=0;
			continue;
		}
		if(bia<bib){
			if(a[i].zifu!=a[o].zifu){
				ans+=bia;
			}
			bib-=bia;
			bia=0;
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	shuru();
	jisuan();
	printf("%lld",ans);
}
