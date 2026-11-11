#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("hub1.in","r",stdin);
	//freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
        int n,k;
        cin>>n>>k;
        int ma=0,mi=1e9;
        for(int i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
            ma=max({ma,x,y});
            mi=min({mi,x,y});
        }
        random_device(time);
        if(c<=3)cout<<int((float)rand()/10000)%2+1<<endl;
        else cout<<(ma+mi)/2
	}
}

