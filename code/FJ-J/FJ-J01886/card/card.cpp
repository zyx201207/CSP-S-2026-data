#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a,s,d,f,g,h,j,k,l,z,x,c,v;
	cin>>a>>s;
	int w[a+3],r[s+3]={0};
	for(d=1;d<=a;d++){
		cin>>w[d];
	}
	for(d=1;d<=a;d++){
		int e[s+3]={0};
		for(g=d;g<=a;g++){
			if(e[w[g]]==0){
				e[w[g]]+=1;
			}else if(e[w[g]]!=0){
				for(h=1;h<=s;h++){
					e[h]=0;
				}
				e[w[g]]+=1;
			}
		}
		
		for(j=1;j<=s;j++){
			if(e[j]!=0){
				r[j]+=1;
			}
		}
	}
	for(k=1;k<=s;k++){
		cout<<r[k]<<" ";
	}
	return 0;
}
