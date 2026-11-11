#include<bits/stdc++.h>


using namespace std;
int main(){
	int a,b,c[100005],f[100005],len=0,d[10005]={0};
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>c[i];
	}
	for(int i=1;i<=a;i++){
		len=0;
		for(int j=i;j<=a;j++){
			len++;
			f[len]=c[j];
			for(int o=len;o>=1;o--){
				if(f[o]==c[j]){
					len=o;
				}
			}
		}
		for(int j=1;j<=len;j++){
			d[f[j]]++;
			//cout<<f[j]<<" ";
		}
		//cout<<endl;
	}
	for(int i=1;i<=b;i++){
		cout<<d[i]<<" ";
	}
}
