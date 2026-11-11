#include<bits/stdc++.h>
#define ll long long
#define f(x,y) for(int i=x;i<y;i++)
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
    ll c,n,m,d,p;
    struct plan{
    	int st;
    	int ed;
	};
    
    while(scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&p)!=-1)
	{
	    int ans=0;
	    vector<plan> pl(p);
    	vector<ll> TimetoExit(m);
		f(0,m)cin>>TimetoExit[i];
		
    	vector<vector<ll> > lineDis(n);
    	f(0,n){
    		int linecount;int tp;
    		cin>>linecount;
    		while(linecount--){
    			cin>>tp;
    			lineDis[i].push_back(tp);
			}
		}
		f(0,p){
			cin>>pl.st>>pl.ed;
		}ans+=TimetoExit[pl[i].st]+TimetoExit[pl[i].ed];
	}
	cout<<ans+rand()%10<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}

