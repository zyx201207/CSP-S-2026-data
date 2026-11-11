#include<bits/stdc++.h>
using namespace std;
bool a[500001];
int b[500001],start=0,d[500001];
int main(){
	ios::sync_with_stdio,cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];	
	}
	int start1=1;
	start=1;
	while(start1<=n){
		for(int i=1;i<=m;i++){
			a[i]=0;
		}
		for(int i=start1;i<=n;i++){
			if(a[b[i]]){
				for(int j=start;j<i;j++){
					a[b[j]]=0;
				}
				start=i;
			}
			a[b[i]]=1;
		}
		for(int i=start;i<=n;i++){
			d[b[i]]++;
		}
		start1++;
		start=start1;
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}
}
