#include<bits/stdc++.h> 
using namespace std;
int n,m,x[800002],a1,a2,p1,p2;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	p2=n;
	p1=n;
	if(m==1){
		cout<<n;return 0;
	}else{
		for(int i=1;i<=n;i++){
			if(x[i]==1){
				a1=i;
			}else{
				a2=i;
			}
		}
		for(int i=n;i>=1;i--){
			if(x[i]==1){
				p1=i;
			}else{
				p2=i;
			}
		}
		cout<<p1-a1<<" "<<p2-a2;return 0;
	}
	return 0;
}
