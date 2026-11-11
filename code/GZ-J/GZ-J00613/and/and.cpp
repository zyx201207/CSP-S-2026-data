//GZ-J00613   胡震洋   遵义航天高级中学 
#include <bits/stdc++.h>
using namespace std;
int f1(int x,int y){
	string a="";
	while(x>0){
		int p=x%2;
		a=char(p)+a;
		x=x/2;
	}
	string b="";	
	while(y>0){
		int p=y%2;
		b=char(p)+b;
		y=y/2;
	}
	
	
	string re="";
	if(a.size()<b.size()){
		string c=a;
		a=b;
		b=c;
	}
	while(b.size()<a.size()){
		b='0'+b;
	}
	for(int i=0;i<a.size();i++){
		if(a[i]=='1'&&b[i]=='1')re=re+'1';
		else re=re+'0';
	}
	int s=1,sum=0;
	for(int i=a.size()-1;i>=0;i--){
		sum+=(re[i]-'0')*s;
		s=s*2;
	}
	return sum;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	int a[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int max=INT_MIN;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(f1(a[i],a[j])>max){
				max=f1(a[i],a[j]);
			}
		}
	}
	cout<<max;
	return 0;
} 
