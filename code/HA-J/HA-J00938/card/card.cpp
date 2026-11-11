#include<bits/stdc++.h>
using namespace std;
long long aa,pp,ls[20005],a[20005],p[20005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int aa,pp;
	cin>>aa>>pp;
	for(int i=1;i<=aa;i++){
		cin>>ls[i];
    }
    for(int i=1;i<=aa;i++){
		for(int j=i;j<=aa;j++){
			if(a[j]==0){
				for(int k=j+1;k<=aa;k++){
					if(ls[j]==ls[k]){
						a[j]=ls[k];
						for(int x=j+1;x<=k;x++){
							a[x]=-1;
						}
					}
				}
			}
		}
		for(int j=i;j<=aa;j++){
			if(a[j]==0){
				p[ls[j]]++;
			}
			else if(a[j]!=0&&a[j]!=-1){
				p[a[j]]++;
			}
		}
		for(int j=1;j<=aa;j++){
			a[j]=0;
		}
	}
	for(int i=1;i<=pp;i++){
		cout<<p[i]<<" ";
	}
	return 0;
}
