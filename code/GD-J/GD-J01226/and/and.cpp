#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],sum;
long long f(int x,int y){
	string s1,s2,s3;
	while(x>0){
		int g=x%2;
		if(g==1)s1='1'+s1;
		else s1='0'+s1;
		x/=2;
	}
	while(y>0){
		int g=y%2;
		if(g==1)s2='1'+s2;
		else s2='0'+s2;
		y/=2;
	}
	if(s1.size()!=s2.size()){
		if(s1.size()>s2.size()){
			while(s1.size()>s2.size())s2='0'+s2;
		}
		else{
			while(s1.size()<s2.size())s1='0'+s1;
		}
	}
	/*for(int i=0;i<s1.size();i++){
		cout<<s1[i];
	}
	cout<<endl;
	for(int i=0;i<s2.size();i++){
		cout<<s2[i];
	}
	cout<<endl;*/
	for(int i=0;i<s1.size();i++){
		if(s1[i]=='1'&&s2[i]=='1')s3+='1';
		else s3+='0';
	}
	/*for(int i=0;i<s3.size();i++){
		cout<<s3[i];
	}
	cout<<endl;*/
	long long b=1,ans=0;
	for(int i=s3.size()-1;i>=0;i--){
		if(s3[i]=='1')ans+=b;
		b*=2;
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++)sum=max(sum,a[i]);
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				//cout<<i<<" "<<j<<endl;
				sum=max(sum,f(a[i],a[j]));
			}
		}
	}
	if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					//cout<<i<<" "<<j<<endl;
					sum=max(sum,f(f(a[i],a[j]),a[k]));
				} 
				
			}
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
