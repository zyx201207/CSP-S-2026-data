#include<bits/stdc++.h>
using namespace std;
int ans,n,m,d[200005];
void dfs(int x,int step,int cnt){
	if(step==m){
		ans=max(ans,cnt);
	}
	if(m-step>n-x+1||x>n){
		return;
	}
	dfs(x+1,step,cnt);
	if(step==0){
		dfs(x+1,step+1,d[x]);
	}
	else{
		bool a[32]={0},b[32]={0};
		int y=d[x],sum=cnt,ccnt=0;
		int s1=0,s2=0;
		while(y){
			s1++;
			if(y%2){
				a[s1]=1;
			}
			y/=2;
		}
		while(sum){
			s2++;
			if(sum%2){
				b[s2]=1;
			}
			sum/=2;
		}
		long long ssum=1;
		for(int i=1;i<=32;i++){
			if(a[i]==1&&b[i]==1){
				ccnt+=ssum;
			}
			ssum*=2;
		}
		dfs(x+1,step+1,ccnt);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>d[i];
	}
	if(n<=20){
		dfs(1,0,0);
	}
	else if(m==1){
		int mmaxd=-1;
		for(int i=1;i<=n;i++){
			mmaxd=max(mmaxd,d[i]);
		}
		cout<<mmaxd;
	}
	else if(m==n){
		int sum=d[1];
		for(int x=2;x<=n;x++){
			bool a[32]={0},b[32]={0};
			int y=d[x],ccnt=0;
			int s1=0,s2=0;
			while(y){
				s1++;
				if(y%2){
					a[s1]=1;
				}
				y/=2;
			}
			while(sum){
				s2++;
				if(sum%2){
					b[s2]=1;
				}
				sum/=2;
			}
			long long ssum=1;
			for(int i=1;i<=32;i++){
				if(a[i]==1&&b[i]==1){
					ccnt+=ssum;
				}
				ssum*=2;
			}
			sum=ccnt;
		}
		ans=sum;
	}
	else if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				int x=d[i],y=d[j];
				bool a[32]={0},b[32]={0};
				int s1=0,s2=0;
				while(x){
					s1++;
					if(x%2){
						a[s1]=1;
					}
					x/=2;
				}
				while(y){
					s2++;
					if(y%2){
						b[s2]=1;
					}
					y/=2;
				}
				long long ssum=1;
				int ccnt=0;
				for(int i=1;i<=32;i++){
					if(a[i]==1&&b[i]==1){
						ccnt+=ssum;
					}
					ssum*=2;
				}
				ans=max(ans,ccnt);
			}
		}
	}
	cout<<ans;
	return 0;
}

