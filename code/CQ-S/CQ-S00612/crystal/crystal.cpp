#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    bool f=true;
    for(int i=1;i<n;i++){
    	if(a[i+1]-a[i]!=a[2]-a[1]){
    		f=false;break;
		}
	}
	if(f==true){
		int d=a[2]-a[1];
		int maxn=(-1+sqrt(1+(8*m)*1.0/d)*1.0)/2;
		cout<<maxn+1;
		return 0;
	}
    int maxn=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i-maxn;j++){
            int num=0,flag=0;
            for(int k=j;k<=i;k++){
                num+=a[i]-a[k];
                if(num>m){flag=1;break;}
            }
            if(flag==0){maxn=max(maxn,i-j+1);}
        }
    }
    cout<<maxn;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
