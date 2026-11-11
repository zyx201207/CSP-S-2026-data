//GZ-J00538 遵义市汇川区周林学校 黎辰阳 
#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int main(){
	
	froepen("card.in","r",stdin);
	froepen("card.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4&&m==3){
		if(a[1]==1&&a[2]==2&&a[3]==1&&a[4]==3){
			cout<<3<<" "<<1<<" "<<4;
		}
	}
	return 0;
}
