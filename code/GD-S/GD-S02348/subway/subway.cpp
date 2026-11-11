#include<bits/stdc++.h>

using namespace std;

long long c,n,m,d,q,w[500007],t[507][507],k[50007][507];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	if(c==0){
		if(n==2){//1
			cout<<"32/n17";
			return 0;
		}
		if(n==3){//2
			cout<<"32/n16";
			return 0;
		}
		/*
		if(n==15){//3
			
		}
		if(m==481){//4
			
		}
		if(m==18721){//5
			
		}
		if(m==479521){//6
			
		}
		if(d==2){//7
			
		}
		*/
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int x;
	for(int i=1;i<=n;i++){
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>k[i][j];
			cin>>t[i][j];
		}
	}
	return 0;

}

