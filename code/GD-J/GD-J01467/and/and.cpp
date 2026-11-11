#include<bits/stdc++.h>
using namespace std;
int tong[35];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int p;
		cin>>p;
		int k=0;
		while(p>0){
			if(p&1){
				tong[k]++;
			}
			p>>=1;
			k++;
		}
	}
	long long ans=0,op=536870912,num=0,kkk;
	for(int i=29;i>=0;i--){
		if(num>=m){
			break;
		}
		if(tong[i]>=m){
			ans+=op;
			num++;
		}
		op/=2;
	}
	cout<<ans;
	return 0;
}

