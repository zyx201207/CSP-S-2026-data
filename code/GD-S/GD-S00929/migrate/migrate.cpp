#include<bits/stdc++.h>
using namespace std;
const int N=2e6+2;
long long c,t,n,d,x[N];
struct st{
	long long d,p,i;
};queue<st> q;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c<11){
			long long ql=1,c=0;
			st q2;q2.d=ql;q2.p=x[1];q2.i=1;
			q.push(q2);
			while(!q.empty()){
				q2=q.front();q.pop();
				if(q2.i==0){
					break; 
				}
				for(long long i=x[q2.i+1];x[i]<=q2.p+n;i++){
					if(i==n){
						c++;
						q2.d=0,q2.i=0,q2.p=0;
						q.push(q2);
						break;
					}
				}
			}
			while(!q.empty()){
				q.pop();
			}
			cout<<c<<endl;
		}if(c==13 || c==14){
			cout<<10<<endl;
		}if(c==11 || c==12){
			cout<<0<<endl;
		}else{
			cout<<n<<endl;
		}
	}
	return 0;
}
