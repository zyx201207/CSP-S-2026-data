//贵阳市第十八中学 刘文浩 GZ-J00572 
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int N1=3e5+10;
int a[N];
int sum[N1];
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int l=0;
	for(int i=0;i<n;i++) cin>>a[i];
	while(l<n-1){
		for(int i=l;i<n;i++){
			for(int j=l;j<i;j++){
				if(a[j]==a[i]){
					i++;
					break;
				}
				else continue;
			}
			for(;i<n;i++) sum[a[i]]++;
		}
		l++;
	}
	for(int i=0;i<m;i++) cout<<sum[i]<<' ';
	return 0;
}
