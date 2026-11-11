#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int duan[200005];
char dx[200005];
signed main(){
	freopen("string.in","r",stdin);	
	freopen("string.out","w",stdout);
	cin>>n;
	char sb=' ';
	int sum=0;
	for(int i=1;i<=n;i++){
		int a;
		char b;
		cin>>a>>b;
		if(b!=sb){
			sum++;
			duan[sum]=a;
			dx[sum]=b;
			sb=b;
		}else{
			duan[sum]+=a;
			dx[sum]=b;
		}
	}
	int yz=0;
	char yzx;
	bool y;
	int ans=0;
	int i=0;
	while(sum>=i){
		if(yz==0){
			yz=abs(duan[i]-duan[sum]);
			i++;
			if(dx[i]==dx[sum]){
				ans+=abs(duan[i]-duan[sum]);
				yzx=dx[i];
				if(duan[i]>duan[sum]){
					y=1;
					sum--;
				}else if(duan[i]==duan[sum]){
					i++,sum--;
				}else{
					y=0;
					i++;
				}
			}else{
				ans+=min(duan[i],duan[sum]);
				if(duan[i]>duan[sum]){
					sum--;
					y=1;
					yzx=dx[i];
				}else if(duan[i]==duan[sum]){
					i++,sum--;
				}else{
					i++;
					y=0;
					yzx=dx[sum];
				}
			}
		}else{
			if(y==1){
				yz=abs(yz-duan[sum]);
				if(yzx==duan[sum]){
					ans+=abs(yz-duan[sum]);
					if(yz<duan[sum]){
						y=0;
						i++;
					}else if(yz==duan[sum]){
						i++,sum--;
					}else sum--;
				}else{
					ans+=min(yz,duan[sum]);
					if(yz<duan[sum]){
						y=0;
						i++;
						yzx=dx[sum];
					}else if(yz==duan[sum]){
						i++,sum--;
					}else sum--;
				}
			}else{
				yz=abs(yz-duan[i]);
				if(yzx==duan[i]){
					ans+=abs(yz-duan[i]);
					if(yz<duan[i]){
						y=1;
						sum--;
					}else if(yz==duan[i]){
						i++,sum--;
					}else i++;
				}else{
					ans+=min(yz,duan[i]);
					if(yz<duan[i]){
						y=1;
						sum--;
						yzx=dx[i];
					}else if(yz==duan[i]){
						i++,sum--;
					}else i++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
