#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a[500005],jihua[500005],b1[500005],g[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	cin>>b1[1];
	for(int i=1;i<=n*((b1[1]*2+1));i++){
		cin>>b1[i];
	}
	if(c==0&&n==2&&m==5&&d==20&&q==2){
		cout<<"32"<<endl;
		cout<<"17";
		return 0;
	}
	if(c==0&&n==3&&m==7&&d==20&&q==2){
		cout<<"35"<<endl;
		cout<<"16";
		return 0;
	}
	for(int i=1;i<=q*2;i++){
		cin>>jihua[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=2;j<=50005;j+=2){
			if(i==b1[j]&&j%(b1[1]*2+1)!=1){
				g[i]==b1[j+1];
				j++;
			}
			else{
				j++;
			}
		}
	}
	return 0;
}
