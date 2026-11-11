#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[500005];
int t[500005];
int t1[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int ans=0;
		for(int j=i;j<=n;j++){
			int flag=0;
			for(int k=1;k<=ans;k++){
				if(t[k]==a[j]){
					ans=k;
					flag=1;
					break;
				}
			}
			if(flag==0){
				ans++;
			    t[ans]=a[j];
			}
			
		}
		for(int i=1;i<=ans;i++){
			t1[t[i]]++;
		}

	}
	for(int i=1;i<=m;i++){
		cout<<t1[i]<<' ';
	}
	return 0;
}