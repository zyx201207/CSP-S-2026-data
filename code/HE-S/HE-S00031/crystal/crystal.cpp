#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a,b,nn[1000000],ans;
ll num;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//------------------------------------------------------------------------------------
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		nn[i]=a;
		b+=a;
	}
	b/=n;
	sort(nn+1,nn+n+1);
	for(num=1;num<n;num++){
		if(nn[num+1]==nn[num]) continue;
		if(nn[num]>=b) break;
	}
	//cout<<num<<' '<<b<<endl;
	b=nn[num];
	for(;num>=1;num--){
		int st=b-nn[num];
		if(m>=st){
			m-=st;
			nn[num]+=st;
			ans++;
		}
		else break;
	}
	cout<<ans<<endl;
	//------------------------------------------------------------------------------------
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
