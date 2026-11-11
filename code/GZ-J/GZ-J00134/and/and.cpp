//GZ-J00134 南白初级中学 唐清倾 
#include <bits/stdc++.h>
using namespace std;
int n,m,mx=INT_MIN;
int a[200001]={};
void dfs(int d,int s,int ans){
	if(s==m){
		mx=max(mx,ans);
		return ;
	}
	for(int i=d;i<=n;i++){
		int t=ans&a[i];
		s++;
		dfs(i,s,t);
		s--;
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		for(int i=1;i<=n;i++){//2*10^5
			cin>>a[i];
			mx=max(mx,a[i]);
		}
		cout<<mx;
	}
	else if(m==n){
		cin>>a[1];
		mx=a[1];
		for(int i=2;i<=n;i++){//2*10^5
			mx=mx&a[i];
		}
		cout<<mx;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){//2*10^5
			cin>>a[i];
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				mx=max(mx,a[i]&a[j]);
			}
		}
		cout<<mx;
	}
	else if(m==n-1){
		cin>>a[1];
		int t=a[1];
		for(int i=2;i<=n;i++){//2*10^5
			t=t&a[i];
		}
	}
	else{
		for(int i=1;i<=n;i++){//2*10^5
			cin>>a[i];
		}
		for(int i=1;i<=n-m+1;i++){
			dfs(i,1,i);
		}
		cout<<mx;
	}
	fclose(stdin);
	fclose(stdout);
}

