#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,i,j,h=0,ma=0,xb,sl=0;
	cin>>n;char u;
	long long l[n+10][2],p[200050];
	for(i=0;i<n;i++){
		cin>>l[i][0]>>u;
		l[i][1]=u-'a';
		h+=l[i][0];
		if(l[i][0]>ma){
			ma=l[i][0];
		}
	}if(n==1){
		cout<<0;
	}else{
		//if(n*ma<200050){
			for(i=0,xb=0;i<n;i++){
				for(j=0;j<l[i][0];j++,xb++){
					p[xb]=l[i][1];
				}
			}for(i=0;i<xb/2;i++){
				if(p[i]!=p[xb-1-i]){
					sl++;
				}
			}
		//}else{
		//}
		cout<<sl;
	}
	
	return 0;
}
