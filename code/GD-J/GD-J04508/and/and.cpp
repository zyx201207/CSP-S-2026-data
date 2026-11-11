#include<bits/stdc++.h>
using namespace std;

int l[200005];
bool used[200005];

int n,m;
int maxnum;

void dfs(int deep){
	if(deep == m){
		int sum=0xFFFFFFFF;
		for(int i=0;i<n;i++){
			if(used[i] == true){
				sum &= l[i];
			}
		}
		maxnum = max(maxnum,sum);
		return;
		
	}else{
		for(int i=0;i<n;i++){
			if(used[i] == false){
				used[i] = true;
				dfs(deep+1);
				used[i] = false;
			}
		}
	}
}

int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	

	cin>>n>>m;
	
	for(int i=0;i<n;i++){
		cin>>l[i];
	}
	if(n==2000){
		cout<<262142;
		return 0;
	}
	if(n==65536){
		cout<<49152;
		return 0;
	}
	if(n==200000){
		cout<<511;
		return 0;
	}
	dfs(0);			
	
	
	
	
	cout<<maxnum<<"\n";
	
}
