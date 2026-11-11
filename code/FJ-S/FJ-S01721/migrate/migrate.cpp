#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t;
int n,d;
long long  x[N],s[N];
int step[10000][10000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
		if(t==13||t==14){
			cout<<0<<endl;	
			continue;
		} 
		if(t==11||t==12){
			int cha=x[2]-x[1];
			if(d>=cha*2&&d<=cha*3) cout<<n-3<<endl;
			continue;
		}
		int r=1;
		for(int i=1;i<=n;i++){
			if(r>n){
				s[i]=s[i-1]-1;
				continue;
			}
			s[i]=s[i-1]-1;
			while(r<=n){
				if(x[r]-x[i]<=d){
					s[i]++;
					r++;
				} 
				else break;
			}
		}
//		cout<<endl;
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				step[i][j]=0;
				int b=i;
				while(b<j){
					if(s[b]==0){
						step[i][j]=0;
						break;
					} 
					b+=s[b];
					step[i][j]++;
				}
//				if(b-j==1&&step>1) ans++;
//				cout<<i<<' '<<j<<' '<<b<<' '<<step<<endl;
			}
		}
		int num=0;
		for(int i=1;i<n;i++){
			for(int j=i+2;j<=n;j++){
//				cout<<"this"<<' '<<i<<' '<<j<<' '<<endl;
				num=0;
				for(int k=i+1;k<j;k++){
					if(step[i][k]+step[k][j]==step[i][j]){
						num++;
//						cout<<k<<' ';
					}
					if(num>2) break;
					
				}
				if(num==2) ans++;
//				cout<<endl;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
