//GZ-S00419 黔南布依族苗族自治州都匀第一中学 孙皓辰

#include<bits/stdc++.h>
using namespace std;
int w[510];
int main(){
	int c;
	cin >>c;
	while(c){
		ios::sync_with_stdio(false);
		cin.tie(0);
        freopen("subway.in","r",stdin);
	    freopen("subway.out","w",stdout);
	    int n, m, d, q;
	    int w[20100];
	    cin >>n>>m>>d>>q;
	    for(int i=1;i<=m;i++) cin >>w[i];
	    int a[501][101],t[501][101];
	    for(int i=1;i<=n;i++){
		    int k;
		    cin >>k;
		    for(int j=1;j<=k;j++) {
			    cin >>a[i][k]>>t[i][k];
	    	}
    	}
    	for(int i=1;i<=q;i++){
    		int qi,zhong;
    		cin >>qi>>zhong;
    		int ans;
    		ans=w[qi]+w[zhong];

    		cout<<ans<<"\n";
		}
		c--;
    }
    return 0;
}
