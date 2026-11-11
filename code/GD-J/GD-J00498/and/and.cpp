#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m,a[200005],tw[]{0,0,1,3,7,15,31,63,127,255,511,1023,2047,4095,8191,16383,32767,65535,131071,262143,524287,1048575};

int dfs(int st,int gm,int rslt){
	
	if(gm==m)
		return rslt;
	
	int maxn=0;
	
	for(int i=st+1;i<=n;i++)
		maxn=max(maxn,dfs(i,gm+1,rslt&a[i]));
		
	return maxn;
}

signed main(){
	ios::sync_with_stdio(0),cin.tie(0);

	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	
	if(m==1){
		int tmp=0,A;
		
		for(int i=1;i<=n;i++) 
			cin>>A,tmp=max(tmp,A);
		
		cout<<tmp;
		
		return 0;
	}
	
	if(n<=20){
		
		for(int i=1;i<=n;i++) cin>>a[i];
		
		cout<<dfs(1,1,a[1]);
		
		return 0;
		
	}
	
	if(m==n){
		
		int tmp,A;
		
		cin>>A,tmp=A;
		
		for(int i=1;i<n;i++) 
			cin>>A,
			tmp&=A;
		
		cout<<tmp;
		
		return 0;
	}
	

	if(n<=2000){
		
		if(m==2){
			int tmp[2005]={},res=0;
			
			for(int i=1;i<=n;i++) cin>>a[i];
			
			for(int i=1;i<n-1;i++){
				tmp[i]=a[i]&a[i+1];
				
				for(int j=i+2;j<=n;j++)
					tmp[i]=max(tmp[i],a[i]&a[j]);
				
				res=max(res,tmp[i]);
			}
			
			cout<<res;
			
			return 0;
		}
		
		
	}
	
	int cnt=0,mn=INT_MAX;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
		mn=min(mn,a[i]);
		
		bool k=0;
			
		for(int j=1;j<=21;j++){
			if(a[i]==tw[j]){
				k=1;
				break;
			}
		}
		
		if(k) cnt++;
	}
		
	if(cnt==n){
		cout<<mn;
		
		return 0;
	}


	return 0;
}
