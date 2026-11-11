#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,cnt=0;
int n,d,x[2000005];
int ne[2000005];
bool check(int p,int i){
	return abs(x[p]-x[i])<=d;
}
int ppp(int i,int j,int step){
	if(ne[i]==-1)return -1;
//	cout<<ne[i]<<"qweqwe\n";
	if(ne[i]>=j)return step;
	else return ppp(ne[i],j,step+1);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		memset(ne,-1,sizeof(ne));
		cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		if(c==11||c==12){
			if(n==1){
				cout<<"0\n";
			} 
			else{
				int cha=x[2]-x[1];
				if(cha>d){
					cout<<"0\n";
				}
				else{
					if(cha*2>d){
						cout<<"0\n";
					}
					else{
						if(cha*3>d){
							cout<<max(0ll,n-3)<<"\n";
						}
						else{
							cout<<"0\n";
						}
					}
				}
			}
			continue;
		}
		for(int i=1;i<=n;i++){
			int l=i+1,r=n,ans=0;
			while(l<=r){
				int mid=l+r>>1;
				if(check(mid,i)){
					l=mid+1;
					ans=mid;
				}
				else{
					r=mid-1;
				}
			}
			if(ans>i)ne[i]=ans;
			else ne[i]=-1;
		}
		for(int i=1;i<=n-3;i++){
			for(int j=i+3;j<=n;j++){
				int ci=ppp(i,j,1);
//				cout<<ci<<"\n";
				int uu=0;
				if(ci<=1)continue;				
				for(int k=i+1;k<j;k++){
					if(x[k]-x[i]>d)break;
					int qq=ppp(k,j,1);
					if(qq==-1)continue;
//					cout<<qq<<"asdasd\n"; 
					if(qq+1==ci)uu++;
				}
//				cout<<uu<<"\n";
				if(uu==2)cnt++;
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
/*
1 1 
6 2
-4 -3 -2 -1 3 6



*/
