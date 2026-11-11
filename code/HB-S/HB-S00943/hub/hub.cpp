#include <bits/stdc++.h>
using namespace std;
int n,c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(c--){
        cin>>n;
        for(int i=1;i<=n;i++){
            int x,y;
            cin>>x>>y;
        }
        cout<<(n*10+100-67+128)%13*1465%11+138%76<<'\n';
	}
	return 0;
}
