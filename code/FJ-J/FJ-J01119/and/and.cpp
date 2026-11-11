#include<bits/stdc++.h>
using namespace std;
struct wy{
	int num;
	string b="";
};
wy a[200005];
int n,dq=0,m,mi,dn=0,ma=-1;
string jg="",zt="";
bool cmp(wy x,wy y){
	return x.b>y.b;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].num;
		int h=a[i].num;
		zt="";
		while(h!=0){
			if(h%2==1){
				zt+="1";
			}else{
				zt+="0";
			}
			h/=2;
		}	
		int bj=zt.size();
		ma=max(bj,ma);
	}
	for(int i=1;i<=n;i++){
		int h=a[i].num;
		zt="";
		while(h!=0){
			if(h%2==1){
				zt+="1";
			}else{
				zt+="0";
			}
			h/=2;
		}
		int op=zt.size();
		for(int j=0;j<ma-op;j++){
			a[i].b+="0";
		}
		for(int j=zt.size()-1;j>=0;j--){
			if(zt[j]=='0'){
				a[i].b=a[i].b+"0";
			}else{
				a[i].b=a[i].b+"1";	
			}
			
		}		
	}
	sort(a+1,a+1+n,cmp);

	mi=n;
	int sc=0;
	for(int i=a[1].b.size()-1;i>=0;i--){
		int g=1;
		while(a[g].b[i]=='1' && g<=n){
			g++;
		}
		if(g-1>=m){
			if(sc==0){
				mi=g-1;	
				jg+="1";	
				sc=1;			
			}else if(g-1<=mi){
				mi=g-1;	
				jg+="1";				
			}

		}else{
			mi=m;
			jg+="0";
		}
	}
	int o=1;
	for(int i=0;i<jg.size();i++){
		if(jg[i]=='1'){
			dn+=o;	
		}
		
		o*=2;
	}
	cout<<dn;
	return 0;
}
