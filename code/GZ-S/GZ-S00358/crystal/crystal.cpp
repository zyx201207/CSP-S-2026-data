//GZ-S00358   遵义市第四初级中学  何雨泽
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	long long s=0;
	long long mi=LONG_MAX;
	long long mii=LONG_MAX;
	long long arr[n+1]={};
	long long cf[n+1]={};
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		cf[i-1]=arr[i]-arr[i-1];
		cout<<cf[i-1]<<' ';
		if(mi>cf[i-1]&&i-1!=0){
			mi=cf[i-1];
			mii=i-1;
		}
	}
	bool p=mii;
	while(m>0){
		if(p==1){
			m-=cf[mii];
			cf[mii]=0;
			s++;
			for(int i=mii;i>=1;i--){
				if(m<0){
					continue;
				}
				else if(m==0){
					continue;
				}
				m-=cf[mii];
			}
			mii++;
		}
		else{
			mii--;
			m-=cf[mii];
			cf[mii-1]+=cf[mii];
			cf[mii]=0;
			p=mii;
		}
	}
	cout<<s;
	return 0;
}

