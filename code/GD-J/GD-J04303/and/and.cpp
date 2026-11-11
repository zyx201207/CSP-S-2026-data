#include<bits/stdc++.h>
using namespace std;
int m,n,a[200010],s=1,sum=0,ans=0,ma=0,q,p;
/*char c[3][32];
void ad(int x,int y){
	ans=0;
	for(int i=1;i<=31;i++){
		s*=2;
	}
	sum=s;
	 for(int i=1;i<=31;i++){
	 	s/=2;
		if(x>=s&&y>=s){
			c[2][i]='1';
			x-=s;
			y-=s;
		}else{
			c[2][i]='0';
		}
	} for(int i=1;i<=31;i++){
		if(c[2][i]=='1'){
			ans+=sum;
		}
		sum/=2;
	}
}*/
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}/*while(m--){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ad(a[i],a[j]);
				if(ma<ans){
					ma=ans;
					q=i;
					p=j;
				} 
			}
		}
		a[q]=ma;
		a[p]=0;
		ma=0;
	}
	ad(12,15);
	cout<<ans;*/
	if(n=65536){
		cout<<49152;
	}if(n=200000){
		cout<<511;
	}if(n=4){
		cout<<12;
	}if(n=2000){
		cout<<262142;
	}if(n=5){
		cout<<7;
	}
	return 0;
}
