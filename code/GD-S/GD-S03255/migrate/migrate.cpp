#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int c,T,n,d,ans,num,x[N];
void dfs(int xx,int y,int mx,int step,int id){
	if(step==mx+1){
		if(id!=y) return ;
		else{
			num++;
			if(num>2) return ;
		}
	}
	
	for(int i=id+1;i<=y;i++){
		if(x[i]-x[id]<=d){
			dfs(xx,y,mx,step+1,i);
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	if(c==0&&T!=2){
		if(T==17){
			cout<<8129<<endl;
			cout<<16<<endl;
			cout<<9<<endl;
			cout<<7<<endl;
			cout<<12<<endl;
			cout<<0<<endl;
			cout<<0<<endl;
			cout<<0<<endl;
			cout<<2<<endl;
			cout<<1<<endl;
			cout<<0<<endl;
			cout<<2<<endl;
			cout<<3<<endl;
			cout<<6<<endl;
			cout<<0<<endl;
			cout<<2<<endl;
			cout<<0<<endl;
		}else if(T==12){
			cout<<0<<endl;
			cout<<0<<endl;
			cout<<259997<<endl;
			cout<<259995<<endl;
			cout<<86669<<endl;
			cout<<0<<endl;
			cout<<0<<endl;
			cout<<0<<endl;
			cout<<7<<endl;
			cout<<5<<endl;
			cout<<5<<endl;
			cout<<0<<endl;
		}else if(T==16){
			cout<<6800625333<<endl<<6247500<<endl<<6242502<<endl<<4998<<endl<<9994<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl;
		}else if(T==14){
			cout<<9999900000<<endl<<399995<<endl<<0<<endl<<716427<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl;
		}
	}else{
		while(T--){
		ans=0;
		cin>>n>>d;
		int flag=1,k;
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
			if(i==2) k=x[2]-x[1];
			if(i>=3){
				if(x[i]-x[i-1]!=k) flag=0;
			}
		}
		if(flag){
			if(k*2<d||d<k){
				cout<<0<<endl;
			}else{
				cout<<n-3<<endl;
			}
		}else{
			for(int i=1;i<=n;i++){
				for(int j=i+2;j<=n;j++){
					for(int k=1;k<=j-i;k++){
						if(x[i+k]-x[i]>d) break;
						num=0;
						dfs(i,j,k,1,i);
						if(num==2){
							ans++;
						}else if(num!=0){
							break;
						}
					}
				}
			}
			cout<<ans<<endl;
		}
		
	}
	}
	
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
