#include<bits/stdc++.h>
using namespace std;
int n,x,a[10001],b[10001],ans,sum,tb;
int maxx=-INT_MAX,fw;
char y;
string s;
void str(int x,int y){
	for(int i=1;i<=x;i++){
		s+=y;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    s=" "+s;
	cin>>n;
	if(n==2){
		cout<<0;
		return 0;
	}
	char c,cc;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		str(x,y);
		sum+=x;
	}
	int mid=sum/2+1;
	int f=sum%2; 
	for(int i=1;i<mid;i++){
		a[int(s[i]-'a')]++;
	}
	 if(f==1){
	 	for(int i=mid+1;i<=s.size();i++){
		b[int(s[i]-'a')]++;
	    }
	 }else{
	 	for(int i=mid;i<=s.size();i++){
		b[int(s[i]-'a')]++;
	   }
	 }
	 for(int i=1;i<=50;i++){
	 	maxx=max(maxx,a[i]);
	 	maxx=max(maxx,b[i]);
	 	if(maxx==a[i]) fw=a[i];
	 	else if(maxx==b[i]) fw=b[i];
	 }
	 if(f==1){
	 	for(int i=1;i<=s.size();i++){
	 		if((s[i]==char(fw+'a') || s[i]==s[sum-i]) && i!=mid){
	 			ans++;
	 		//	cout<<i<<"\n";
			 }
			 }
	 }
	 else if(f==0){
	 	for(int i=1;i<=s.size();i++){
	 		if(s[i]==char(fw+'a') || s[i]==s[sum-i]){
	 			ans++;
	 			//cout<<i<<"\n";
			 }
			 }
		 }
	 cout<<ans;
	return 0;
}

