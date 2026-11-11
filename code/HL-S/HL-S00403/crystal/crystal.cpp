#include<bits/stdc++.h>
using namespace std;
long long m,n,caonum,maxn,linmax;
long int shui[614514];
struct sss{
	long long zhi;
	int shuliang=0;
	long long lastdis;
}num[666666];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%ld",&shui[i]);
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	sort(shui+1,shui+1+n);
	num[1].zhi=shui[1];
	num[1].shuliang=1;
	num[1].lastdis=0;
	int k=1,ye=1;
	for(int i=2;i<=n;i++){
		ye=1;
		if(shui[i]==shui[i-1]){
			num[k].shuliang++;
		}else{
			k++;
			ye=0;
			num[k].shuliang++;
			num[k].zhi=shui[i];
		}
		if(ye==0){
			num[k].lastdis=num[k].zhi-num[k-1].zhi;
		}
	}
	int zuo=1,you=1;
	while(you<k){
		you++;
		caonum=0;
		linmax=num[zuo].shuliang;
		for(int i=zuo;i<you;i++){
			caonum+=(num[you].zhi-num[i].zhi)*num[i].shuliang;
			linmax+=num[i+1].shuliang;
		}
		if(caonum>m){
			while(caonum>m){
				if(num[zuo].shuliang>=1){
					linmax--;
					num[zuo].shuliang--;
					caonum-=num[you].zhi-num[zuo].zhi;
				}else{
					zuo++;
				}
			}
		}
		if(maxn<linmax) maxn=linmax;
	}
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}