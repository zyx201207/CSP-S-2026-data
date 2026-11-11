#include<bits/stdc++.h>
using namespace std;
int er[500][1000];
long long ej(int w) {
	int x=w,h=0;
	while(x){
		if(x%2==1){
			er[w][h]=1;
			h++;
		}
	}
}

int cmp(int a,int b){
	return a<b;
}

int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n=0,m=0,a=0,t[10000],mot=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>t[i];
		ej(t[i]);
	}
	sort(t+0,t+n,cmp);
	for(int i=0;i<4;i++){
		mot+=(er[t[i]][i]&er[t[i+1]][i])*pow(2,i);
	}
	cout<<mot;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
