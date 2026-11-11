#include<bits/stdc++.h>
using namespace std;
int din[2005],n,m;
int zhuan(int x){
	int a[10000],wei=0;
	while(x!=0){
		a[wei]=x%2;
		x/=2;
	}
	int ans=0;
	for(int i=wei;i>=1;i--){
		ans=ans*10+a[i];
	}
	return ans;
}
int bi(int x,int y){
	int a[10000],b[10000],c[10000],awei=0,bwei=0,cwei=0,t1=0,t2=0,q;
	while(x!=0){
		a[awei]=x%10;
		awei++;
		x/=10;
	}
	while(y!=0){
		b[bwei]=y%10;
		bwei++;
		y/=10;
	}
	if(bwei>awei){
		t2=bwei-awei;
	}
	if(bwei<awei){
		t1=awei-bwei;
	}
	if(t2!=0){
		q=awei;
	}else{
		q=bwei;
	}
	for(int i=1;i<=q;i++){
		if(a[i+t1]==1&&b[i+t2]==1){
			c[i]=1;
		}else{
			c[i]=0;
	}
	cwei++;
	}
	int ans=0;
	for(int i=cwei;i>=1;i--){
		ans+=c[i]*((cwei-i)^2);
	}
	return ans;
}
int main(){
	//freopen("and.in","r",stdin);
	//freopen("ans.out","w",stdout);
	cin>>n>>m;
	int fin=0;
	for(int i=1;i<=n;i++){
	cin>>din[i];
	if(din[i]>fin){
		fin=din[i];
		}	
	}
	int ans=0;
	if(m==1){
		cout<<fin;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			int e=zhuan(din[i]);
			for(int j=i;j<=n;j++){
				if(i==j){
					continue;
				}else{
					ans=max(ans,bi(e,zhuan(din[j])));
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
