#include<iostream>
using namespace std;
int d[500005],e[500005],f[300005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a,b,c,i=0,j=0,w,z,g;
	cin>>a>>b;
	for(i;i<a;i++){
		cin>>c;
		d[i]=c;
	}
	for(i=0;i<a;i++){
		j=0;
		for(w=i;w<a;w++){
			e[j]=d[w];
			for(z=0;z<=j;z++){
				if (e[z]==e[j]){
					j=z;
					break;
				}
			}

			j++;
			 
		}
		for(w=0;w<=j;w++){
			g=e[w];
			
			f[g-1]++;
		}
	}
	for(i=0;i<b;i++){
		cout<<f[i]<<" ";
	}
	return 0;
} 
