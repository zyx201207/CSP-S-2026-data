






#include<bits/stdc++.h>
using namespace std;

int sz[500005];
int ans[300005];

bool zxt(int a1,int b1){//zhaoxiangtong
	
	for(int i=a1;i<=b1;i++){
		for(int j=i+1;j<=b1;j++){
			if(sz[i]==sz[j]){
				return true;
			}
		}
	}
	
	return false;
}


void zss(int a,int b){//zongsousuo
	if(a==b){
		ans[sz[a]]+=1;
	}
	
	else if(!zxt(a,b)){
		for(int i=a;i<=b;i++){
			ans[sz[i]]+=1;
		}
	}
	else{
		int zhao=sz[a];
		for(int i=b;i>=a;i--){
			if(zhao==sz[i]){
				ans[zhao]+=1;
				zss(i+1,b);
				return;
			}
		}
	}
}



int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	//ios::sync_with_stdio(0),cin.tie(0);
	
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>sz[i];
	}
	for(int i=0;i<n;i++){
		zss(i,n-1);
	}
	
	for(int i=1;i<=m;i++){
		cout<<ans[i];
		if(i!=m) cout<<' ';
	}
	return 0;
}


//4 3
//1 2 1 3

//10 3
//3 1 2 1 3 2 3 1 2 1



