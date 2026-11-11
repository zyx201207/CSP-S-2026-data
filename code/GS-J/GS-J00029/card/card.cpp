#include<bits/stdc++.h>
using namespace std;
int n,m,c[200009];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	} 
	if(m=2){
		int a=0,b=0;
		for(int t=1;t<=n;t++){
			map<int ,bool>mp;
			if(n-t+1==2){
				a++,b++;
			}
			else if(n-t+1<2){
				if(c[n]==1){
					a++;
				}else{
					b++;
				}
			}else{
				if(c[t]==c[n]&&c[t]==1){
					a++;
				}
				else if(c[t]==c[n]&&c[t]==2){
					b++;
				}
				else {
					a++,b++;
				}
			}
		}
		cout<<a<<" "<<b;
	}
	return 0;
}
