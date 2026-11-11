#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<1<<endl;
		return 0;
	}
	int sum1=0,sum2=0;
	if(m==2){
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				sum1++;
			}else{
				sum2++;
			}			
		}
		if(a[1]==1){
			cout<<n<<" "<<sum2<<endl;
		}else{
			cout<<sum1<<" "<<n;
		}
	}
	
	return 0;
}
