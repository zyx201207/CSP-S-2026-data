#include<bits/stdc++.h>
using namespace std;
int c[600000],d[600000],o=0,e[600000],k;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a,b;
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>c[i];
	}
	for(int h=1;h<=a;h++){
		o=0;
		for(int i=a;i>0;i--){
			o++;
			for(int j=i;j<=a;j++){
				if(d[j]==c[i]){
					for(k=j;j<=i;j++){
						d[j]=0;
					}
					o=i-k;
					break;
				}
			}
			d[o]+=c[i];
		}
		for(int i=1;i<=o;i++){
			if(e[d[o]]<=h){
				e[d[o]]++;
			}
		}
	}
	for(int i=1;i<=sizeof(e);i++){
		cout<<e[i]<<" ";
	}
	return 0;
} 
