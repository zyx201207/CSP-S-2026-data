#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card2.in","r",stdin);
	freopen("card2.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n],b[m];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		b[i]=0;
	}
	for(int i=0;i<n;i++){
		int j=0;
		b[a[i]]++;
		for(int v=0;v<n;v++){
			if(b[a[i]]>i+1){
				for(j=0;j<i-1;j++){
					if(a[j]==a[i]){
						break;
					}
				}
				for(int z=j;z<i-1;z++){
					b[a[z]]--;
				}
			}
		}
				
	}
	for(int i=0;i<m;i++){
		cout<<b[i]<<' ';
	}
	return 0;
} 
