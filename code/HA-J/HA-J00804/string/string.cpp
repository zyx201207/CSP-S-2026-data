#include<bits/stdc++.h>
using namespace std;
long long a[200009];
char b[200009];
int w[16]={0};
void jia(int q){
	int d=0;
	for(int i=15;i>=0;i--){
		int q1=q%10;
		q=q/10;
		w[i]=w[i]+q1+d;
		d=w[i]/10;
		w[i]=w[i]%10;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int q;
	cin>>q;
	int z=0,y=q-1;
	for(int i=0;i<q;i++)
		cin>>a[i]>>b[i];
	while(z!=y){
		if(a[z]>a[y]){
			if(b[z]==b[y]){
				a[z]=a[z]-a[y];
				y--;
			}
			else{
				jia(a[y]);
				a[z]=a[z]-a[y];
				y--;
			}
		}
		else if(a[z]==a[y]){
			if(b[z]==b[y]){
				y--;
				z++;
			}
			else{
				jia(a[z]);
				y--;
				z++;
			}
		}
		else{
			if(b[z]==b[y]){
				a[y]=a[y]-a[z];
				z++;
			}
			else{
				jia(a[z]);
				a[y]=a[y]-a[z];
				z++;
			}
		}
	}
	int bj=0;
	for(int i=0;i<16;i++){
		if(bj==0&&w[i]!=0){
			cout<<w[i];
			bj=1;
		}
		else if(bj==1)cout<<w[i];
	}
	return 0;
}
