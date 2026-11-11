#include<bits/stdc++.h>

using namespace std;
long long l_n,l_m,l_a[500006],lm[500006],cha[500006],cntm[500006];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&l_n,&l_m);
	for(int i=1;i<=l_n;i++){
		scanf("%lld",&l_a[i]);
	}
	 
	for(int i=1;i<=l_n;i++){
		fill(lm+1,lm+1+l_m,0);
		fill(cha+1,cha+1+l_n,0);
		for(int j=i;j<=l_n;j++){
			if(lm[l_a[j]]){
				lm[l_a[j]]=1;
				int f=1;
				for(f=i;l_a[f]!=l_a[j];f++);
				cha[f]=-1;
				cha[j]=1;
			}
			else{
				lm[l_a[j]]++;
			}
		}
//		for(int j=i;j<=l_n;j++){
//			cout<<cha[j];
//		}
//		cout<<endl;
		
		long long cnt_=0;
		for(int j=i;j<=l_n;j++){
			cnt_+=cha[j];
			if(cnt_>=0){
				cntm[l_a[j]]++;
			}
		}
//		for(int j=1;j<=l_n;j++){
//			if(lm[l_a[j]]==1){
//				cntm[l_a[j]]++;
//			}
//		}
	}
	for(int i=1;i<=l_m;i++){
		
		printf("%lld",cntm[i]);
		if(i!=l_m)printf("\n");
	}
	return 0;
}
