#include<bits/stdc++.h>

using namespace std;
const int N= 5e5+10;
int n,m;
int a[N];
int f[N];
int laoda[N];
int diff[N];
int ans[N];
int o[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >>n>>m;
	for(int i = 1;i <= m;i++)laoda[i] = -1;
	for(int i = 1;i <= n;i++){
		cin >>a[i];
	}
	for(int i =n;i >= 1;i--){
		if(laoda[a[i]] == -1){
			laoda[a[i]] = i;
		}
		else{
			f[i] = laoda[a[i]];
			diff[i]++;
			diff[i+1]--;
		}
	}
	//cout <<"0";
	for(int i = 1;i <= n;i++){
		//cout <<laoda[a[i]]<<" ";
		int k=i;
		for(int j = i;j >= 1;j--){
			if(laoda[a[j]] > i){
				//cout <<i<<endl;
				k = i-j;
				break;
			}
		}
		//cout <<k<<endl;
		//cout <<k<<" ";
		ans[a[i]]=ans[a[i]]+k;
	}
	for(int i = 1;i <= m;i++){
		cout <<ans[i]<<" ";
	}
	return 0;
}
//10 3 3 1 2 1 3 2 3 1 2 1 