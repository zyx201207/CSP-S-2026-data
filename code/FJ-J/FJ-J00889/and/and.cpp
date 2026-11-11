#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005],m;bool o[200005];int zhang,jia;bool p[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(i==1)jia=a[1];
		else jia&=a[i];
	}
	for(int i=32;i>=0;--i){
		int ge=0,jie=0;
		memset(p,0,sizeof(p));
			for(int j=1;j<=n;++j){
			if((a[j]>>i)&1&&!o[j]){
				if(jie==0)jie=a[j];
				else jie&=a[j];
				++ge;
			}else{
				p[j]=1;
			}
		    }
		if(ge==m)return cout<<jie,0;
		else if(ge>m){
			for(int j=1;j<=n;++j){
				o[j]|=p[j];
				//cout<<o[j]<<' '; 
			}//cout<<endl;
		}//cout<<ge<<endl;
	}
	int jie=0,ge=0;
	for(int i=1;i<=n;++i){
		if(!o[i]){
			if(jie==0)jie=a[i];
			else jie&=a[i];
			++ge;
		}
	}
	if(ge>=m)cout<<jie;
	else cout<<jia;
	return 0;
} //凡王之血，必以剑终 
