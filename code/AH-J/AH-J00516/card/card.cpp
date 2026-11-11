#include<bits/stdc++.h>
using namespace std;
int pd,pf[500005],sum[500005],n,m,a[500005],l=0;
bool p;
void  yi(int x){
	pd=x;
	for(int i=pd;i<=n;i++){
		pf[i]=0;
	}
	pd++;
}
void chu(){
	for(int i=0;i<=n;i++){
		pf[i]=0;
	}pd=1;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(l<=n){
		chu();
		for(int i=max(1,l);i<=n;i++){
			p=true;
			for(int j=1;j<pd;j++)
				if(pf[j]==a[i]){
					yi(j+1);p=false;}
			if(p) pf[pd]=a[i],pd++;
		}
		for(int i=l;i<=pd;i++){
			sum[pf[i]]++;
		}
		l+=1;
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	cout<<endl;
	return 0;
}
