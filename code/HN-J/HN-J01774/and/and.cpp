#include<bits/stdc++.h>
using namespace std;
int ax[300001];
int ay[300001];
int az[300001];
int azz[300001];
int azzz[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a,b,k=1,kk;cin>>a>>b;
	for(int i=1;i<=a;i++)cin>>ax[i];
	for(int i=1;i<=a;i++){
		for(int j=i;j<=a;j++){
			if(ay[ax[j]]==0){
			ay[ax[j]]=1;
			az[k]=ax[j];
			k++;
			}
			else{
			for(int aa=1;aa<k;aa++){
				if(az[aa]==ax[j]){
					kk=i;
					k=1;
				}
				for(int aa=kk;aa<=kk;aa++){
					az[aa]=0;
				}
			}	
			}
			}
			for(int j=1;j<=a;j++){
				if(az[i]!=0)azz[i]++;
			}
	}
	for(int i=1;i<=a;i++)cout<<azz[i]<<' ';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
