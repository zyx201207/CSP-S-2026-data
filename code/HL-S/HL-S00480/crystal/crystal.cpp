#include<bits/stdc++.h>

using namespace std;
int shuliang/*1*10^9*/,gs;
long long cishu;
long long nl[501000],cha[501000];
bool sheng(int a,int b){
	return a<b;
}
void shi(int djg,long long sjc,int jg){
	
	sjc-=cha[djg]*jg;
	if(sjc>=0){
		djg++;jg++;
		
	}
	else{
		if(gs<jg){gs=jg;}
		return;
	}
	if(djg==shuliang-1){
			if(gs<jg){gs=jg;}
		return;
	}
	shi(djg,sjc,jg);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
		
	cin>>shuliang>>cishu;
	
	for(int i=0;i<shuliang;i++){
		cin >>nl[i];
	}
	//wocuole
	if(shuliang>=5001){
		sort(nl,nl+shuliang,sheng);
		int lklnb=nl[12]-nl[11];
		if(lklnb==0){
			printf("%d",shuliang);
			return 0;
		}
		else if(lklnb>cishu){
			printf("1");
			return 0;
		}
		else if(lklnb==cishu){
			printf("2");
			return 0;
		}
		else {
			double nd=cishu/lklnb;
			double dn=nd*2;
			int asdf=sqrt(dn);
			for(int i=asdf;i>0;i++){
				if(i*(i+1)>=dn&&i*(i-1)<=dn){
					printf("%d",i);
					return 0;
				}
			}
			
			return 0;
			
		}
	}
	//wocuole
	sort(nl,nl+shuliang,sheng);
	for(int i=0;i<shuliang-1;i++){
		cha[i]=nl[i+1]-nl[i];
	}
	for(int i=0;i<shuliang-1;i++){
		shi(i,cishu,1);
	}
	printf("%d",gs);
	fclose(stdin);
	fclose(stdout);
	return 0;
}//duijin***