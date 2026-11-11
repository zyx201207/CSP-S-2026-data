#include<bits/stdc++.h> 
using namespace std;
int a[1000];
int main(){
	int n,m,cnt=0;cin>>n>>m;
	for(int j=1;j<=n;j++){
		cin>>a[j];
		for(int i=0;i<=m;i++){
			if(a[j]==a[j+1]) cnt+=1;
			else if (a[j]<a[j+1]) {
				a[j]+=1;
				if(a[j]==a[j+1]) cnt+=1;
				continue;
			}
			else if (a[j]>a[j+1]) {
				a[j+1]+=1;
				if(a[j]==a[j+1]) cnt+=1;
				continue;
			} 
			continue;
		}	
	}
	cout<<cnt/m;
	return 0;
}
