#include<bits/stdc++.h>

using namespace std;
int n,m,a[500005],c[500005],d[300006];
int main(){
	ifstream("D:\GD-J02607\card\card.in");
	ofstream("D:\GD-J02607\card\card.out");
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int p=1;p<=n;p++){
		for(int i=1;i<=p;i++)d[i]++;
		for(int i=1;i<=p;i++){
			for(int j=i+1;j<=p;j++){
				if(a[i]==a[j]){
					for(int o=i+1;i<j;o++){
						d[o]--;
					}
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}
}
