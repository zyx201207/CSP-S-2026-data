#include<bits/stdc++.h>
using namespace std;
int a[200005];
int n,m,ans=0;
int aand(int a,int b){
	string a1,b1,c;
	while(a!=0){
		a1+=a%2;
		a/=2;
	}
	reverse(a1.begin(),a1.end());
	while(b!=0){
		b1+=b%2;
		b/=2;
	}
	reverse(b1.begin(),b1.end());
	if(a1.size()<b1.size()){
		while(a1.size()!=b1.size()){
			a1='0'+a1;
		}
	}
	if(a1.size()>b1.size()){
		while(a1.size()!=b1.size()){
			b1='0'+b1;
		}
	}
	for(int i=0;i<a1.size();i++){
		if((a1[i]==0&&b1[i]==0)||(a1[i]==1&&b1[i]==0)||(a1[i]==0&&b1[i]==1))c+='0';
		else c+='1';
	}
	int an=0,shi=1;
	for(int i=0;i<c.size();i++){
		an+=(c[i]-'0')*shi;
		shi*=2;
	}
	return an;
}
void baosou(int index,int mm,int cnt){
	//cout<<index<<" "<<mm<<" "<<cnt<<endl;
	if(index==n||mm==0){
		ans=max(ans,cnt);
		return;
	}
	for(int i=index+1;i<n;i++){
		baosou(i,mm-1,aand(cnt,a[i]));
		baosou(i,m,pow(2,15));
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	baosou(0,m,pow(2,15));
	cout<<ans;
	return 0;
}
