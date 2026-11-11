#include<bits/stdc++.h>


using namespace std;
int a,b,c[200005],g[200005],len=0,k[200005],len2=0;;
long long sum=0;
int d[200005][31];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a;
	cin>>b;
	for(int i=1;i<=a;i++){
		cin>>c[i];
		int e=c[i];
		int f=0,h[35];
		while(e){
			f++;
			h[f]=e%2;
			e/=2;
		}
		for(int j=1;j<=f;j++){
			int y=h[j];
			d[i][j]=y;
		}
	}
	int i=30;
	for(;i>=1&&len<b;i--){
		for(int j=1;j<=a;j++){
			if(d[j][i]==1){
				len++;
				g[len]=j;
			}
		}
		if(len<b){
			len=0;
		}
	}
	int z=1;
	for(int o=1;o<=i;o++){
		z*=2;
	}
	sum+=z;
	if(i==0){
		sum--;
	}
	i+=1;
	while(i>=2){
		i--;
		for(int j=1;j<=len;j++){
			if(d[g[j]][i]==1){
				len2++;
				k[len2]=g[j];
			}
		}
		z/=2;
		if(len2<b){
			len2=0;
		}
		else{
			len=len2;
			for(int j=1;j<=len2;j++){
				g[j]=k[j];
			}
			len2=0;
			sum+=z;
		}
	}
	cout<<sum;
}
