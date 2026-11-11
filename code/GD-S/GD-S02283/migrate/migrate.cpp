#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t;
	cin >> c >>t;
	
	int n,d;
	
	while(t--){
		cin >> n >> d;
	
		int a[n];
		for(int i=0;i<n;i++) cin >> a[i];//岛屿 
		int s[n-1];
		for(int i=0;i<n-1;i++) s[i]=a[i+1]-a[i];//岛屿之间的路径差 
	
		int num=0;
		for(int i=0;i<n-1;i++){
			if((s[i]<=d && s[i+1]+s[i+2]<=d) && (s[i]+s[i+1]<=d && s[i+2]<=d)) num++;
		}
		cout << n-num << endl;
	}

	
	
	
	
	return 0;
}
