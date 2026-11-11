#include<bits/stdc++.h>
using namespace std;
#define int long long
int x[1000098];
void chhh(){
		int n,d;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		int cut=0,num=0,a=d*d,flg=0;
		for(int z=1;z<=n-3;z++){
			int b=a+z;
			cut=0;
			int l=z+1,r=n;
			while(l<r){
				int mid=(l+r)/2;
				if(x[mid]<b){
					l=mid+1;
				}else{
					r=mid;
				}
				flg=l;
			}
			for(int v=z+1;v<=flg;v++){
				if(x[v]-x[z]<=d&&x[flg]-x[v]<=d){ 
					cut++;
				}
			}
			if(cut==2){
				num++;
			}
		}
		cout<<num*d*d<<endl;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		chhh();
	}
	return 0;
}
		

