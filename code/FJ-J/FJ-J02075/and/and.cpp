#include<bits/stdc++.h>
using namespace std;
string b[200005],s1,s2,s3;
int n,m,a[200005];
string s(int x){
	string y;
	while(x!=0){
		y+=char('0'+x%2);
		x/=2;
	}
	return y;
}
void and1(){
	for(int i=0;i<max(s1.size(),s2.size());i++){
		if(s1[i]=='1'&&s2[i]=='1'){
			s3[i]='1';
		}else{
			s3[i]='0';
		}
	}
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		b[i]=s(a[i]);
	}
	s3=b[1];
	for(int i=1;i<=m;i++){
		s1=s3;
		s2=b[i];
		and1();
	}
	int sum=0,ji=1;
	for(int i=0;i<s3.size();i++){
		sum+=(s3[i]-'0')*ji;
		ji*=2;
	}
	cout<<sum;
	return 0;
}
