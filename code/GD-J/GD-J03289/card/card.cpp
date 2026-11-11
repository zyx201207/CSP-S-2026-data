#include<bits/stdc++.h>
using namespace std;
main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long m,a,b,d,e[500000]={},c[500000]={},q[500000]={},ll;
	cin>>a>>m;
	b=0;
	ll=a;
	d=0;
	for(int i=1;i<=a;i++){
		cin>>c[i];
	}
	b=0;
	for(int i=1;i<=a;i++){
		for(int j=1;j<=a;j++){
			d=0;
			for(int k=1;k<=b;k++){
				if(q[k]==c[j]&&c[j]!=0){
					c[j]=0;
					ll--;
					d=k;
					break; 
				}
			}
			if(d==0&&c[j]!=0){
				q[b]=c[j];
				b++;
			}else{
				for(int k=d;k<=b;k++){
					q[k]=0;
				}
				b=d;
			}
			for(int k=1;k<=b;k++){
				e[q[k]]++;
			}
			if(ll==b){
				break;
			}
		}
		if(ll==b){
			break;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<e[i]<<" ";
	}
	return 0;
}
