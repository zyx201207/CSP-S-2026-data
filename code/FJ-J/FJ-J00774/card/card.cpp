#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500050];
int b=0;
int c=0;int sum=0;
int n,m;
void get_15(){
	for(int i=1;i<=m;i++){
		 if(i!=sum&&a[n]!=sum){
		 	cout<<n<<" "<<b;
		 	return ;
		 }else if(i!=sum&&a[n]==sum){
		 cout<<c<<" "<<n;
		 return ;
}
else if(i=sum&&a[n]==sum){
		 cout<<n<<" "<<c;
		 return ;
}else if(i=sum&&a[n]==sum){
		 cout<<b<<" "<<n;
		 return ;
}
	}
}
	
signed main(){
//freopen("card.in","r",stdin);
 //freopen("card.out","w",stdout);
cin>>n>>m;
int ans=0;

int cnt=0; 
int  u=0;
for(int i=1;i<=n;i++){
	cin>>a[i];
    sum=a[1];
    
}
if(m==1){
cout<<n;
return 0;
}
for(int i=1;i<=n;i++){
	if(sum==a[i])b++;
	else c++;
}
if(n==m){
	for(int i=1;i<=m;i++){
		cout<<n;
		if(i!=m)cout<<" ";
	}
return 0;
}
	if(n<=5&&m<=2){
		get_15();
	}
return 0;
}
