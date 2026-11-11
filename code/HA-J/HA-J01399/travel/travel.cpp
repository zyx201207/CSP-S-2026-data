#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int n,m,i,j,k,l;
string str[4];
	if(c1==c2)  return 1;
	else  return 0;
	if(n==m)  return 1;
	else  return 0;
	for(int i=1;i<4;++i){
		for(int j=1;j<=3;++j){
			if(i!=j&&i==1||2||3&&j==1||2||3){
				for(int k=1;k<=2;++k){
					for(int l=1;l<=2;++l){
						if(k!=l&&k==1||2&&l==1||2){
							return 1;
						}
						else{
							return 0;
					}
						if(j+1==i||i+1==j||l+1==k||k+1==l){
							return 1;
						}
						else{
							return 0;
					}
				}
			}
		}
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	cin>>str[];
	cout<<str[];
	return 0;
}
