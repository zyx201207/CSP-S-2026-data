#include<bits/stdc++.h>
using namespace std;
#define int LL
typedef long long LL;
const int N=2000010;
int c,t,n,d,x;
int a[N],cf[N],q[N];
int tong[N];
signed main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	freopen("migrate.cpp","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int ant=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
//			cf[i]=cf[i]-cf[i-1];
		}
//		for(int i=1;i<=n;i++){
//			q[i]=q[i-1]+cf[i];
//		}
		if(n>5000){
			x=a[2]-a[1];//等差数列
			int len=d/x*2;//i与i+len-1为岛屿对
			if(n>=len&&len!=2){
				cout<<n-len+1<<"\n";
			}else{
				cout<<"0\n";
			}		
		}else{//找出a中的所有等差数列 
			memset(tong,0,sizeof(tong));
			int gs=0;
			for(int i=1;i<n;i++){
				int l=1,gc,last;//l为等差数列长度 gc为公差 last为上一个数
				for(int j=i+1;j<=n;j++){
					gc=a[j]-a[i];
					last=a[i];
					for(int k=j;k<=n;k++){
						if(a[k]-last==gc){
							l++;
							last=a[k];
						}
					}
					int len=d/gc*2;			
					if(l>=len&&len>=4){
						for(int k=1;k<=gs;k++){
							if(gc==tong[k]){
								continue;
							}
						}
//						cout<<len<<" "<<gc<<" "<<i<<"\n";
						ant+=l-len+1;
						gs++;
						tong[gs]=gc;
					}
				}
			}
			cout<<ant<<"\n";
		}
		
	}
	return 0;
}