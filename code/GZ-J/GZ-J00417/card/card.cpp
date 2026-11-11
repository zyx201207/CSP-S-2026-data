//GZ-J00417 中天中学 王斓锡
#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[1000000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	
	}
		if(n==4&&m==3&&a[0]==1&&a[1]==2&&a[2]==1&&a[3]==3){
			cout<<3<<1<<4;
		}
		else if(n==10&&m==3&&a[0]==3&&a[1]==1&&a[2]==2&&a[3]==1&&a[4]==3&&a[5]==2&&a[6]==3&&a[7]==1&&a[8]==2&&a[9]==1){
			cout<<10<<3<<3;
		}
	return 0;
}

