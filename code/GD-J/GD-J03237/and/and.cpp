#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<long long> a;
long long Count=-1;
void dfs(int p,long long and_,int rem){
	if(rem==0){
		Count=max(Count,and_);
		return ;
	}
	if(p==n) return ;
	if(p+rem>n) return ;
	
	if(rem==m)
		dfs(p+1,a[p],rem-1);
	else
		dfs(p+1,and_&a[p],rem-1);
	
	dfs(p+1,and_,rem);
	
	return ; 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a.push_back(x);
	}
	if(m==1){
		long long Ans=-1;
		for(int i=0;i<n;i++)
			if(a[i]>Ans) Ans=a[i];
		cout<<Ans;
	}
	else if(m==n){
		long long Ans=0;
		for(int i=0;i<n;i++)
			Ans+=Ans&a[i];
		cout<<Ans;
	}
	else if(m==2){
		if(n<=10000){
			long long Ans=-1;
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					long long q=a[i]&a[j];
					if(q>Ans)
						Ans=q;
				}
			}
			cout<<Ans;
		}
		else{
			sort(a.begin(),a.end());
			long long Ans=-1;
			for(int i=n-1;i>=1;i--){
				long long q=a[i]&a[i-1];
				if(q>Ans)
					Ans=q;
			}
			cout<<Ans;
		}
	}
	else if(n<=200){
		dfs(0,0,m); 
		cout<<Count;
	}
	else{
		long long Ans=0;
		sort(a.begin(),a.end());
		for(int i=n-1;i>=0;i--){
			if(m==0) break;
			if(Ans==0) Ans=a[i];
			else Ans=Ans&a[i];
			m--;
		}
		cout<<Ans;
	}

	return 0;
}

