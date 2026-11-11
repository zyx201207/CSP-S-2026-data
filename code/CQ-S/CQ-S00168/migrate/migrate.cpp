#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t,n,d,ans;
int a[2000005];
int f(int x,int end,int ans){//ans表示路径长度 
	if(x==end) return 1;
	if(x>end) return 0;
	int min_t=2100000000,sum=0;
	for(int i=x+1;i<=x+d;i++){
		int t=f(i,end,ans+1);
		if(t<min_t){
			sum=1;
			min_t=t;
		}
		else{
			sum++;
		}
	}
	return sum;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        ans=0;
        for(int i=1;i<=n;i++){
            cin >> a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int t=f(i,j,0);
                if(t==2){
                	//cout << i << " " << j << endl;
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
