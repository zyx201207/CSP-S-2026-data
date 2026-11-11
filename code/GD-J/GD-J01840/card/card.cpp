#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int all[n],an[m]={0},top=0,d[n]={0};
	for(int i=1;i<=n;i++) cin>>all[i];
	for(int i=1;i<=m;i++){
		for(int j=i-1;j<=n;j++){
			d[top]=all[j];
			top++;
			for(int c=0;c<top;c++){
				if(d[c]==d[top]){
					for(int s=c;s<=top;){
						d[s]=0;
						top--;
					}
				}
			}
		}
		for(int anser=1;anser<=m;anser++){
			for(int r=0;r<=top;r++) if(d[r]==anser){an[anser]++;
			d[r]=0;}
		}
		top=0;
	}
	for(int i=1;i<=m;i++) cout<<an[i]<<" ";
    return 0;
}
