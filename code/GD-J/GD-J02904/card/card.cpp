#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
int n,m,x=0,y=0,sum1=0,sum2=0;
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
}
if(m==1){
	cout<<n;
}
else if(m==2){
for(int i=1;i<=n;i++){
	for(int j=1;j<=n;j++){
		if(j!=n&&a[j]==1){
			x=1;
		}
		if(j!=n&&a[j]==2){
			y=1;
		}
	}
	if(a[n]==1&&x==1){
		sum1++;
	}
	else if(a[n]==1&&x==0&&y==1){
		sum1++;
		sum2++;
	}
	else if(a[n]==1&&x==0&&y==0){
		sum1++;
	}
	else if(a[n]==2&&y==1){
		sum2++;
	}
	else if(a[n]==2&&x==1&&y==0){
		sum1++;
		sum2++;
	}
	else if(a[n]==2&&x==0&&y==0){
		sum2++;
	}
}
cout<<sum1<<" "<<sum2;	
}
else if(m>=2){
	for(int i=1;i<=m;i++){
		cout<<n<<" ";
	}
}
}
