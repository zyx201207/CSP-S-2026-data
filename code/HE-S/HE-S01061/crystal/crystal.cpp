#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	 
	int m,//操作数 
	n;//水晶数 
	cin >> n >> m;
	int sj[n];//水晶 
	for(int i=0;i<n;i++){
		cin >> sj[i];
	}
	
	int ms[n][2]={};//补齐第[n]需要的操作数 [2]是补齐后的水晶数 
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(sj[i]>=sj[j]){
				ms[i][0]+=sj[i]-sj[j];
				ms[i][1]++;
			}
		}
	}
	
	int ans=0;
	for(int i=0;i<n;i++){
		if(ms[i][0]<=m && ms[i][1]>ans){
			ans=ms[i][1];
		}
	} 
	cout << ans;
	
	return 0;
} 
