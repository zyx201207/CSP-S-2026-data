#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int main(){
	ios::sync_with_stdio(true);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n;
	cin>>n;
	if(n<=5){
		int m;
		cin>>m;
		if(m==1){
			cout<<n;
			return 0; 
		}
		if(m==2){
			int num[10]={},num1=0,num2=0;
			for(int i=1;i<=n;i++){
				cin>>num[i];
				if(num[i]==1)
				  num1++;
				else
				  num2++;
			}
			if(num[n]==1){
				cout<<n<<" "<<num2;
				return 0; 
			}
			cout<<num1<<" "<<n;
		}
		return 0;
	}
	int m;
	cin>>m;
	int num[N]={},ans[N]={},now=1,j=1;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		if(num[i]!=now)
		  ans[j]=i-1,now=num[i],j++;
	}
	ans[m]=n;
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
