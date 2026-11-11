 #include<bits/stdc++.h>
 using namespace std;
 int n,m,a[200001],mx_ans;
 void xx(int step,int ans,int i2){
 	
 	for(int i=i2;i<=n+step-m;i++){
 		if(step==0) ans=a[i];
 		if(step+1<m) xx(step+1,ans&a[i],i+1);
		if(step+1==m) mx_ans=max(mx_ans,ans&a[i]);
	}
	
 }
 int main(){
 	freopen("and.in","r",stdin);
 	freopen("and.out","w",stdout);
 	cin>>n>>m;
 	for(int i=0;i<n;i++) cin>>a[i];
 	xx(0,0,0);
 	cout<<mx_ans;
 	fclose(stdin);
 	fclose(stdout);
 	return 0;
 }
