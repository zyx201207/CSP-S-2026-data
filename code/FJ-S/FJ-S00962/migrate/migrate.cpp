#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,T;
int n,d,res;
int x[2000005],a[2000005];
int num(int s,int e){
	int dis[5005],shor[5005],ans=0;
	memset(dis,0,sizeof dis);
	memset(shor,0x3f,sizeof shor);
	shor[s]=0;
	int w=s,f=d;
	while(w!=e+1){
		if(x[w-1]>d) return -1;
		f=d;
		for(int i=1;i<=w-s;i++){
//			cout<<"i:"<<i<<endl;
//			cout<<"f-x:"<<f-x[w-i]<<" f:"<<f<<" x:"<<x[w-i]<<endl;
			if(f-x[w-i]>=0){
//				dis[i]=dis[w-i]+1;
				if(shor[w-i]+1==shor[w]){
					if(w==e)ans++;
				}
				else{
					if(shor[w-i]+1<shor[w]){
						if(w==e)ans=1;
						shor[w]=shor[w-i]+1;
					}
				}
//				cout<<shor[w-i]<<' '<<w-i<<' '<<shor[w]<<' '<<w<<endl;
				f-=x[w-i];
//				cout<<"f:"<<f<<endl;
			}
			else{
				break;
			}
		}
		w++;
	}
	if(ans==2) return 1;
	else return 0;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		res=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
	  		cin>>a[i];
	  		x[i-1]=a[i]-a[i-1];
		}
//		for(int i=1;i<=n;i++) cout<<x[i]<<' ';
//		cout<<endl;
		for(int i=1;i<=n;i++){
			for(int j=i+d+1;j<=n;j++){
//				cout<<i<<' '<<j<<' '<<"ans:"<<num(i,j)<<endl;
				if(num(i,j)==-1) continue;
				if(num(i,j)==1) res++;
			}
		}
		cout<<res<<endl;
	}  
    return 0;
}

