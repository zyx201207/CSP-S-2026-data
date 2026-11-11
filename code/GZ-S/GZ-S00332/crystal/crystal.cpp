//GZ-S00332 贵阳市第三中学 韦朝博凯 
 #include<bits/stdc++.h>
 using namespace std;
 const int N=5e5+1;
 long long n,m,ans,u;
 long long a[N],b[N];
 int main(){
 	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
 	cin>>n>>m;
 	for(int i=1;i<=n;i++){
 		cin>>a[i];
	 }
	 sort(a+1,a+n+1);
	 for(int p=1;p<=n;p++){
	 ans=max(1ll*ans,u);
	 u=0;
	for(int j=0;j<=n;j++){
		b[j]=0;
	}
	int g=0;
	 for(int i=p;i<=n+1;i++){
	 	g++;
	 	int q=i-p;
	 	if(a[i]-a[i-1]<0){
	 		b[i]=b[i-1]-(a[i]-a[i-1])*q;
		 }
	 	else b[i]=b[i-1]+(a[i]-a[i-1])*q;
	 	if(m>=b[i]){
	 		u=g;
		 }
	 }
	}
	cout<<ans;
 }
 
