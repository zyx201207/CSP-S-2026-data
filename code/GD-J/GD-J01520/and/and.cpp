#include<bits/stdc++.h>
using namespace std;
long long shu;
const int MAXN=2*100000+5;
int c[MAXN];
int pertwo[MAXN][32];
int er(int a,int num){
	int i=1;//i为下标 
	while(a){
		pertwo[num][i++]=a%2;
		a/=2;
	}
	i--;
	return i;//i为位数 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int min_wei=33,max_wei=0,max_xiabiao;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		er(c[i],i);
		min_wei=min(min_wei,er(c[i],i));
		if(c[i]>max_wei){
			max_wei=c[i];
			max_xiabiao=i;
		}
	}
	int ans=0;
	if(m==n){
		for(int i=1;i<=min_wei;i++){
			bool flag=1;
			for(int j=1;j<=n;j++){
				if(pertwo[j][i]==0){
					flag=0;
					break;
				}
			}
			int k1=i-1,s=1;
			if(flag){
				while(k1--){
					s*=2;
				}
				ans+=s;
			}
		}
	}
	if(m==1){
		ans=c[max_xiabiao];
	}
	if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				int ams=0;
				for(int k=1;k<=32;k++){
					if(pertwo[i][k]==pertwo[j][k]&&pertwo[i][k]==1){
						int s=1,k1=k-1;
						while(k1--){
							s*=2;
						}
						ams+=s;
					}
				}
				ans=max(ams,ans);
			}
		}
	}
	cout<<ans;
	return 0;
} 
