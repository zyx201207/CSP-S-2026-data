#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
void caozuo(int* desktop,int flower_color,int& now){
	bool is = true;
	for(int i = 1;i <now;i++){
		if(is == false){
			desktop[i] = 0;
			continue;
		}
		if(desktop[i] == flower_color){
			is = false;
			now = i+1;
		}
	}
	if(is){
		desktop[now] = flower_color;
		now++;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[n+1] = {0};
	int tong[m+1] = {0};
	int desktop[n+1] = {0};
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	int i = 2; 
	while(i<=n+1){
		int j = i-1;
		i++;
		int now = j;
		for(;j<=n;j++){
			caozuo(desktop,a[j],now);
		}
		for(int t = 1;t<=n;t++){
			tong[desktop[t]]++;
		}
		for(int t = 1;t<=n;t++){
			desktop[t] = 0;
		}
	}
	for(int t = 1;t<=m;t++){
		cout << tong[t] << " ";
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
