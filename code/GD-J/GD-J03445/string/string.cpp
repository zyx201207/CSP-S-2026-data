#include<bits/stdc++.h>
using namespace std;
long long int n,a[200005],c[200005],cnt=0,zh=0;
char b[200005];
long long int zm[30];
string s;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);	
cin>>n;
for(int i=1;i<=n;i++){
	cin>>a[i]>>b[i];
if(zm[b[i]-96]==0) cnt++;
zm[b[i]-96]=zm[b[i]-96]+a[i];
zh+=zm[b[i]-96];	
}	
int e=1,q=1,y=e;
c[1]=a[1];
for(int i=1;i<=n-1;i++){
if(b[i]!=b[i+1]) e++;
c[e]+=c[i+1];

}	

bool w=1;	
while(q<=e/2){
	if(c[q]!=c[n-q+1]){
	w=0;
	break;	
	}
	q++; 
}	
if(w==1){
	cout<<"0";
	return 0;
}	
else{
long long int tong=1;
for(int i=1;i<=cnt;i++){
for(int j=1;j<=cnt;j++){
	if(zm[i]==zm[j]&&zm[i]>tong){
	tong=zm[i];	 
	}
}	
}
int sum=0;
for(int i=1;i<=cnt;i++) if(tong==zm[i]) sum++;
 cout<<min(zh-tong,tong);

}	



	
fclose(stdin);
fclose(stdout);	
}
