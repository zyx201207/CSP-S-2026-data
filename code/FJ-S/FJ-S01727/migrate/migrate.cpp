#include<bits/stdc++.h>
using namespace std;

const int N=2e6+10;

long long a[N]; 

int tmr[N],tmred[N],f[N];

queue<int>q;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int c,t;cin>>c>>t;
	
	while(t--){
//		memset(tmred,0,sizeof(tmred));
		long long n,d;cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		int ans=0;
		memset(tmr,0x3f,sizeof(tmr));
		for(int k=1;a[1]+d>=a[k];k++){
			
			for(int hd=k;hd<=n;hd++){
				if(tmr[hd]==0x3f3f3f3f){
					tmred[1]=hd;tmr[hd]=1;
				}
				int ptr=tmred[tmr[hd]]+1;
				while(a[hd]+d>=a[ptr]&&ptr<=n){
					if(tmr[hd]+1==tmr[ptr])
						f[ptr]++;
					else if(tmr[hd]+1<tmr[ptr])
						f[ptr]=1,tmr[ptr]=tmr[hd]+1,tmred[tmr[hd]+1]=ptr;
					ptr++;
				}
	//			for(int i=1;i<=n;i++)
	//				cout<<tmr[i]<<' ';
	//			cout<<'\n';
	//			for(int i=1;i<=n;i++)
	//				cout<<f[i]<<' ';
	//			cout<<'\n';
			}
			
	//		for(int i=1;i<=n;i++)
	//			cout<<tmr[i]<<' ';
	//		cout<<'\n';
	//		for(int i=1;i<=n;i++)
	//			cout<<f[i]<<' ';
	//		cout<<'\n';
			for(int i=1;i<=n;i++)
				ans+=f[i]==2;
		}
		cout<<ans<<'\n';
	}
	
	return 0;
	
}


//if(11<=c&&c<=12){
//			long long D=a[2]-a[1];
//			if(2*D<=d&&d<3*D){
//				cout<<n-3<<'\n';
//			}else{
//				cout<<0<<'\n';
//			}
//		}

//q.push(1);
//		tmred[1]=1;tmr[1]=1;
//		while(!q.empty()){
//			int hd=q.front();q.pop();
//			int ptr=tmred[tmr[hd]]+1;
//			while(a[hd]+d<=a[ptr]){
//				if(tmr[hd]+1==tmr[ptr])
//					f[ptr]++;
//				else if(tmr[hd]+1<tmr[ptr])
//					f[ptr]=1,tmr[ptr]=tmr[hd]+1,tmred[tmr[hd]+1]=ptr;
//				ptr++;
//			}			
//		}
