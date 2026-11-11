#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int c,T,n,d,a[N],s[N];

int res,step=LLONG_MAX,r;

void dfs(int pos,int ed,int cnt){
//	cout<<pos<<"\n\n";
	if(pos==ed){
//		cout<<cnt<<"\n\n";
		if(cnt<step){
			step=cnt;
			res=1;
		}else if(cnt==step){
			res++;
		}
		return;
	}
	if(cnt>step) return;
	for(int i=pos+1;i<=ed;++i){
		if(a[i]-a[pos]>d) break;
		dfs(i,ed,cnt+1);
	}
}



signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	if(c==11||c==12){
		while(T--){
			cin>>n>>d;
			for(int i=1;i<=n;++i){
				cin>>a[i];
			}
			int cha=a[2]-a[1];
			if(d<cha){
				cout<<0<<'\n';
				continue;
			}
			int sg=d/cha;
			int ans=0;
			for(int i=1;i<=sg;++i){
				ans+=((n-i)/sg-1)*(sg-1)+(n-i-(n-i)/sg*sg);
			}
			cout<<ans<<'\n';
//			for(int i=1;i<=n;++i){
//				s[i]=s[i-1]+a[i];
//			}
//			for(int i=1;i<=n;++i){
//				for(int j=i+1;j<=n;++j){
//					
//				}
//			}
		} 
		return 0;
		
		
		
	}else{
		// bruteforce n<=9
		while(T--){
			cin>>n>>d;
			for(int i=1;i<=n;++i){
				cin>>a[i];
			}
			r=0;
			for(int st=1;st<=n;++st){
				for(int ed=st+1;ed<=n;++ed){
					bool f=false;
					step=LLONG_MAX;
					for(int i=st+1;i<=ed;++i){
						if(a[i]-a[i-1]>d) f=true;
					}
					if(f) break;
					res=1;
					dfs(st,ed,1);
//					if(st==2&&ed==3){
//						cout<<step<<"\n\n\n\n";
//					}
//					cout<<step<<"\n\n";
//					cout<<res<<"\n\n\n";
					if(res==2){
//						cout<<st<<' '<<ed<<'\n';
						++r;
					}
				}
			}
			cout<<r<<'\n';
		}
		
		
		
		
		
	}
}
