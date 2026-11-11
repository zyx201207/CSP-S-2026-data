#include<bits/stdc++.h>
using namespace std;
long long n,m,max_ans,ans;
long long ai[500050];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool dc=true;
	for(int i=0;i<n;i++){
		cin>>ai[i];
		if(i>0){
			if(ai[i]-ai[i-1]!=1) dc=false;
		}
	}
	if(dc==true){
		int mi=m;
		ans=1;
		for(int i=n-2;i>=0;i--){
			if(mi>=ai[n-1]-ai[i]){
				mi-=ai[n-1]-ai[i];
				ans++;
			}
			else{
				break;
			}
		}
		cout<<ans;
	}
	
	else{
		sort(ai,ai+n);
		max_ans=ans=0;
		for(int i=1;i<n;i++){
			int mi=m;
			ans=1;
			for(int j=0;j<i;j++){
				if(mi>=ai[i]-ai[j]){
					mi-=ai[i]-ai[j];
					ans++;
				}
				else{
					break;
				}
			}
			max_ans=max(max_ans,ans);
		}
		cout<<max_ans;
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
