#include<bits/stdc++.h>
using namespace std;
int s,n,m,z[50][200005],b[50],y[50][200005];
long long ans,x;
long long fj(int i){
	long long x=0;
	int a[200005];
	for(int j=1;j<=b[i];j++){
		a[j]=z[i][j];
	}
	x+=1;
	for(int j=i-1;j>0;j--){
		x*-2;
		if(b[j]>=m){
			bool t=true;
			for(int k=1;k<=b[i];k++){
				if(y[j][a[k]]==0){
					t=false;
					break;
				}
			}
			if(t){
				x++;
			}
		}
	}
	return x;
}
long long fz(int i){
	long long x=0;
	int a[200005];
	for(int j=1;j<=b[i];j++){
		a[j]=z[i][j];
	}
	x++;
	for(int j=i-1;j>=1;j--){
		x*=2;
		if(b[j]>=m){
			if(b[j]==m){
				bool t=true;
				for(int k=1;k<=b[i];k++){
					if(y[i][z[j][k]]==0){
						t=!t;
						break;
					}
				}
				if(t){
					for(int k=j-1;k>=1;k--){
						x*=2;
					}
					x+=fj(j);
					break;
				}
			}else{
				int t=0;
				for(int k=1;k<=b[i];k++){
					if(y[i][z[j][k]]==1){
						t++;
					}else{
						z[j][k]=-1;
					}
				}
				if(t==m){
					for(int k=j-1;k>=1;k--){
						x*=2;
					}
					x+=fj(j);
					break;
				}else if(t>m){
					for(int k=j-1;k>=1;k--){
						x*=2;
					}
					x+=fz(j);
					break;
				}
			}
		}
	}
	return x;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&x);
		int t=0;
		while(x!=0){
			t++;
			if(x%2==1){
				b[t]++;
				z[t][b[t]]=i;
				y[t][i]=1;
			}
			x/=2;
		}
		s=max(s,t);
	}
	for(int i=s;i>=1;i--){
		if(b[i]>=m){
			if(b[i]==m){
				ans=fj(i);
				break;
			}else{
				ans=fz(i);
				break;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
