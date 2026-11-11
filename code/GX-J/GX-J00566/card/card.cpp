#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m;
int a[N],top,q[N],cnt[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int mm=1;
	for(int i=1;i<=n;i++){
		
		for(int j=i;j<=n;j++){
			for(int k=1;k<=top;k++){
				if(q[k]==a[j]){
					top=j;
					q[top]=a[j];
					break;
				}
			}
			q[++top]=a[j];
		}
		for(int i=1;i<=top;i++){
			if(q[i]==mm) cnt[mm]++;
		}
		mm++;
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
}
