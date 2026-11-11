#include<bits/stdc++.h>
using namespace std;

vector<long long>a;
vector<long long>dj;

bool cmp(long long a,long long b){
	return a<b;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	long long n,m;
	
	cin>>n>>m;
	a.resize(n+1,0);
	dj.resize(n+1,0);
	
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	sort(a.begin()+1,a.end(),cmp);
	
	for(long long i=1;i<=n;i++)
		dj[i]=dj[i-1]+((i-1)*(a[i]-a[i-1]));
	
	long long ans=0;
	for(long long i=1;i<=n;i++){
		if(dj[i]==m){
			ans=i;
			for(long long j=i;j<=n;j++){
				if(dj[i]==dj[j])
					ans++;
				else
					break;
			}
			
			break;
		}else if(dj[i]>m){
			ans=i-1;
			for(long long j=i;j<=n;j++){
				if(dj[i]==dj[j])
					ans++;
				else
					break;
			}
			
			break;
		}
	}
	
	cout<<ans-1<<endl;

	return 0;
}
