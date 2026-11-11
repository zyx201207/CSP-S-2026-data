//GZ-J00547 张运航 贵阳市第十九中学
#include<bits/stdc++.h>
using namespace std;
int n,m,t=0;
const int N=600000;
int a[N]={};
int s[N]={};
int b[N]={};
bool zs(int y){
	for(int i=0;i<t;i++){
		if(s[i] == y){
			return 1;
		}
	}
	return 0;
}
void cdd(int x){
	t=0;
	for(int i=x;i<n;i++){
		if(zs(a[i])){
			while(s[t] != a[i]){
				t--;
			}
		}s[t] = a[i];
		t++;
	}
	for(int i=0;i<t;i++){
		b[s[i]]++;
	}
	
}

int main(){
	freopen("card.in","w",stdin);
	freopen("card.out","r",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cdd(i);
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	
	
	
	return 0;
} 

