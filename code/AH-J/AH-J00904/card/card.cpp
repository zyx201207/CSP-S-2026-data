#include<bits/stdc++.h>
using namespace std;
string s;
int n,m,a[500005],b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
    	b[i]=a[i];
    	for(int j=i-1;j>=1;j++){
    		if(b[j]==a[i]){
    			for(int o=j;o<i-2;o++){
    				b[o]=0;
				}

			}
		}
	}
	int sum=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(b[j]==a[i])sum++;
		}
		cout<<sum<<' ';
	}
	return 0;
}//Trick||Treat!
