#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d;
long long a[2000010];
long long s[2000010];
long long ans,cnt,num=1e18;
set<string> st;
void solve(int x,int y,long long sum,long long res,string g){
	if(x==y){
		if(num>sum){
			num=sum;
			cnt=1;
			st.clear();
			st.insert(g);
		}
		if(num==sum&&st.count(g)==0){
			st.insert(g);
			cnt++;
		}
		return ;
	}
	if(sum>=num){
		return ;
	}
	if(s[x]<=d){
		if(res+s[x+1]<=d){
			solve(x+1,y,sum,res+s[x+1],g);
		}
		int h=x+1;
		string hh;
		while(h){
			hh+=(char)(h%10+48);
			h/=10;
		}
		solve(x+1,y,sum+1,0,g+hh);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		bool flag=1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>2){
				if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
					flag=0;
				}
			}
		}
		if(flag==1){
			if(d>2){
				cout<<0<<endl;
				continue;
			}
			int k=a[2]-a[1];
			cout<<n-((d/k)+1)<<endl;
			continue;
		}
		for(int i=1;i<n;i++){
			s[i]=a[i+1]-a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+d+1;j<=n;j++){
				cnt=0;
				num=2e9;
				if(s[i]<d)
				solve(i,j,1,s[i],"");
				else
				solve(i,j,1,0,"");
				if(cnt==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
