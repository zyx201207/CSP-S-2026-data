#include<bits/stdc++.h>
using namespace std;
int a[10005];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int num=0;
	for(int i=0;i<m;i++){
		if(a[i] < a[n/2-1]){
			a[i]+=1;	
		}
		if(a[i] == a[n/2-1]){
			num++;	
		}
	}
	cout<<num+1;
	return 0;
}
