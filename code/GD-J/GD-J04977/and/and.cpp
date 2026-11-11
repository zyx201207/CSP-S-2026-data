#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200100],mm,cnt,b[200100];
void dfs(int c){
	if(c==m){
		long long ans=a[b[0]];
		for(int i=1;i<m;i++){
			ans&=a[b[i]];
		}cnt=max(ans,cnt);
		return;
	}else{
		if(c==0){
			for(int i=0;i<n-m+1;i++){
				b[c]=i;
				dfs(c+1);
			}return;
		}else{
			for(int i=b[c-1]+1;i<n-m+c+1;i++){
				b[c]=i;
				dfs(c+1);
			}return;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		mm=max(mm,a[i]);
	}if(m==1){
		cout<<mm;
	}else if(m==2){
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				cnt=max(cnt,a[i]&a[j]);
			}
		}cout<<cnt;
	}else if(m==n){
		cnt=a[0];
		for(int i=1;i<n;i++){
			cnt&=a[i];
		}cout<<cnt;
	}else{
		dfs(0);
		cout<<cnt;
	}
	return 0;
}
