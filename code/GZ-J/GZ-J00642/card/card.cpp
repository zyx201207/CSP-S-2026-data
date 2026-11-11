//贵阳市第二十九中学刘一锐GZ-J00642
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[200000],b[100000],c[100000];
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		int o=0;
		for(int j=i;j<n;j++){
			int f=1;
			for(int k=0;k<o;k++){
				if(b[k]==a[j]){
					f=0;
					o=k+1; 
					break;
				}
			}
			if(f){
				b[o]=a[j];
				o++;
			}
		}
		for(int i=0;i<o;i++){
			c[b[i]-1]++;
		}
	}
	for(int i=0;i<m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
