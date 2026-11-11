#include<bits/stdc++.h>
using namespace std;
int n,as[200001],m;
int w(int a,int b){
	bool aa[1000000001]={0},bb[1000000001]={0},cc[1000000001];
	int ar=0,br=0,ans=0;
	while(a!=0){
		aa[ar]=a%2;
		ar++;
		a/=2;
	}
	while(b!=0){
		bb[br]=b%2;
		br++;
		b/=2;
	}
	for(int i=0;i<ar;i++){
		cc[i]=aa[i] and bb[i];
	}
	for(int i=ar-1;i>=0;i--){
		ans*=2; 
		ans+=cc[i];
	}
	return ans;
}
int dg(int jg,int ans,int dnl){
	if(dnl>n+1){
		return 0;
	}
	if(jg==m){
		return ans;
	}
	int s=0;
	if(jg==0){
		s=dg(1,as[dnl],dnl+1);
	}
	else{
		s=dg(jg+1,w(as[dnl],ans),dnl+1);
	}
	if(s<ans){
		return dg(jg,ans,dnl+1);
	}
	//s=;
	return max(s,dg(jg,ans,dnl+1));
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>as[i];
	}
	cout<<dg(0,0,1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
