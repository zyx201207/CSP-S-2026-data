#include <bits/stdc++.h>
using namespace std;

int n,m,cnt,ans,aaa,b[10086],c[10086];
string a[10005];
string now,net;
bool ccc(string c1,int cnttt){
	while(cnttt--){
		c[c1[cnttt]-1+1]=0;}
	while(cnttt--){
		c[c1[cnttt]-1+1]+=1;}
		return 0;
};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(n==m){for(int i=0;i<n;i++){cout<<n<<" ";}return 0;}
	for(int i=0;i<n;i++){
		cin>>a[i];}
//	while(ans<n){
//		for(int j=ans;j<n;j++){
//			now=now+a[j];
//			c[a[j]-"0"]+=1;
//			cnt++;
//			if(c[a[j]-1+1]>1){
//				aaa=0;
//				while(cnt!=0){
//					net[aaa]=now[aaa];
//					aaa++;}
//				net[aaa+1]=a[j];
//				now=next;
//				net="";
//				ccc(now,m);
//			}}
	for(int ii=0;ii<m;ii++){
		if(c[ii]==0){cout<<1;}
		else{cout<<c[ii];}}
		
	
	
	return 0;}
