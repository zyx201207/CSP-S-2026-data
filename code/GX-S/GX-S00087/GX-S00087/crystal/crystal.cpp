#include<bits/stdc++.h>
using namespace std;

int n;
long long m;
long long a[500005];
long long ans;

struct pai{
	int su;
	int g;
	}b[500005];
	
bool cmp(long long x,long long y){
   return x>y;
}


int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1,cmp);
    int o=1;
    b[1].su=a[1];
    b[1].g=1;
	for(int i=2;i<=n;i++){
		if(a[i]!=a[i-1]){
			o++;
			b[o].g=1;
			b[o].su=a[i];
		}
		else{
			b[o].g++;
		}
	}
	for(int i=1;i<o;i++){
		int x=m;
		int j=i+1;
		long long ansz=0;
		while(b[i].su-x<=b[j].su&&j<=o){
			if((b[i].su-b[j].su)*b[j].g<=x){
				ansz+=b[j].g;
				x-=(b[i].su-b[j].su)*b[j].g;
				j++;
			}
			else
			{
				ansz+=x/(b[i].su-b[j].su);
				x=0;
			}
		}
		ans=max(ans,ansz+b[i].g);
		
	}
	cout<<ans;
	return 0;
}

