#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
vector<int>b[N];
long long n,c,t,d,ans,nod[N];
bool f[N],F=1;
void SE(int x,int y){
	long long mi=INT_MAX,cnt=0;
	queue<int>q;
	queue<long long>l;
	q.push(x);
	l.push(0);
	while(!q.empty()){
		long long Q=q.front(),L=l.front();
		if(Q==y){
			if(L<mi){
				mi=L;
				cnt=1;
			}else if(L==mi){
				cnt++;
			}
		}else if(Q<y){
			for(int i=0;i<b[Q].size()&&b[Q][i]<=y;i++){
				
				q.push(b[Q][i]);
				l.push(L+1);
				
			}
		}
		q.pop();
		l.pop();
	}
	if(cnt==2){
		ans++;
	}
	
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		msmset(b,0,sizeof(b));
		msmset(nod,0,sizeof(nod));
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>nod[i];
			for(int j=i-1;j>=1;j--){
				if((nod[i]-nod[j])<=d){
					b[j].push_back(i);
					
				}
			}
		}
		for(int st=1;st<n-2;st++){
			for(int en=st+3;en<=n;en++){
				SE(st,en);
			}
		}
	}
	cout<<ans;
	return 0;
}
