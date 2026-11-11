//GZ-J00354 湄潭县茶城中学 孟梓涵 
#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200002];
string s1,s2,s3;
string er(int z){
	string s;
	while(z>0){
		if(z%2==0){
		    s+='0';
		    z/=2;
	    }
		else {
			s+='1';
			z/=2;
		}
	}
	return s;
}
int y(int z,int b){
	s1=er(z);
	s2=er(b);
	s3="";
	for(int i=0;i<min(s1.size(),s2.size());i++){
		if(s1[i]=='1' && s2[i]=='1')s3+='1';
		else s3+='0';
	}
	int qwe=0,asd=0,index=0;
	for(int i=s3.size()-1;i>=0;i--){
		asd=s3[i]-'0';
		qwe+=asd*pow(2,i);
	}
	return qwe;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){
			if(a[j]<a[j+1]){
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	int sum=a[1];
	for(int i=2;i<=m;i++){
		sum=y(sum,a[i]);
	}
	cout<<sum;
	return 0;
}
