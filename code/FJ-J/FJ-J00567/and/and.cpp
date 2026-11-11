#include<bits/stdc++.h>
using namespace std; 
int n,m,a[200005],tans_1,tans_2,ans,tk,tk_2,tkf=-1;
bool cmp(int sx,int sy){
	return sx>sy;
}
bool sf(int q){
	bool pd=1;
	while(q){
		if(q%2==1){
			pd=0;
			break;
		}q/=2;
		tkf++;
	}return pd;
}
void bl(int mt,int nt,int zans){
	if(mt>n-nt+1)return;
	if(mt==0||nt>n){
		ans=max(ans,zans);
		return;
	}else{
		if(zans==0){
			bl(mt-1,nt+1,a[nt]);
			bl(mt,nt+1,zans);
			return ;
		}
		bl(mt-1,nt+1,zans&a[nt]);
		bl(mt,nt+1,zans);
		return;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1)tans_1=a[1];
		else tans_1&=a[i];
		tans_2=max(tans_2,a[i]);
		if(a[i]>=4)tk=1;
		if(a[i]!=i-1)tk_2=1;
	}if(m==1){
		cout<<tans_2;
		return 0;
	}else if(m==n){
		cout<<tans_1;
		return 0;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}cout<<ans;
	}else if(tk==0){
		sort(a+1,a+1+n,cmp);
		if(a[m]==2)cout<<a[m];
		else{
			int tans_3=0;
			for(int i=1;i<=n;i++){
				if(a[i]%2==1)tans_3++;
			}if(tans_3>=m)cout<<1;
			else cout<<0;
		}
	}else if(n<=20){
		bl(m,1,0);
		cout<<ans;
	}
	else if(sf(n)&&tk_2==0){
		if(m>n/2)cout<<0;
		else{
			ans=1;
			int er=1;
			for(int i=1;i<tkf;i++){
				ans*=2;
			}int yf=n/4;
			er=ans;
			while(yf>=m){
				yf/=2;
				er/=2;
				ans+=er;
			}
		}cout<<ans;
	}
	else{
		sort(a+1,a+1+n,cmp);
		cout<<a[m]; 
	}
	return 0;
} 
