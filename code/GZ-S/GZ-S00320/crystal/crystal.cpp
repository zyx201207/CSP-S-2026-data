//GZ-S00320 遵义市第十六中学 何世灏 
#include <bits/stdc++.h>
using namespace std;

int a1[500005];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	int o=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%d",&a1[i]);
	sort(a1+1,a1+1+n);
	if(a1[1]==a1[n]){
		cout<<n;
		return 0;
	}else{
		bool st=1;
		for(int i=2;i<=n;i++){
			if(a1[i]-a1[i-1]==1) st=0;
		}if(st){
			int o=0;
			for(int i=1;i<=n;i++){
				if(m<o){
					cout<<i;
					return 0;
				}o+=n;
			}
		}
	}
	for(int i=n;i>=1;i--){
		int y=i-1,j=1,mm=m;
		if(o>i) break;
		while(y>0){
			if(a1[y]<0){
				if(a1[i]+abs(a1[y])<=mm){
					j++;
					mm-=(a1[i]+abs(a1[y]));
				}else{
					break;
				}
			}else if(a1[y]>=0){
				if(a1[i]-a1[y]<=mm){
					j++;
					mm-=(a1[i]-a1[y]);
				}else{
					break;
				}
			}y--;
		}o=max(j,o);
	}cout<<o;
	fclose(stdin);
	fclose(stdout);
	return 0; 
}

