#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
string s1,s2,s3;
int max_;
void and_(int a,int b){
	while(a!=0){
		string g=a%2+"0";
		a=a%2;
		s1=g+s1;
	}
	while(b!=0){
		string z=b%2+"0";
		b=b%2;
		s2=z+s2;
	}
	int min_=min(s1.size()-1,s2.size()-1);
	for(int i=1;i<=min_;i++){
		if(s1[i]==s2[i]){
			s3="1"+s3;
		}
		else{
			s3="0"+s3;
		} 
	}
	int y;
	int p=1;
	for(int i=s3.size()-1;i>=1;i--){
		int yy=s3[i];
		y=(yy-'0')*p;
		p=p*2;
	}
	max_=max(y,max_);
	s1=s2=s3="";
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			and_(a[i],a[j]);
		}
	}
	cout<<max_<<endl;
	return 0;
}
