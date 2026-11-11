//GZ-J00675,遵义航天高级中学,郑子彧 
#include<bits/stdc++.h>
using namespace std;
long long a,b;
int k[10001];
int py(string z){
	int a=0;
	int f=1;
	int l=z.size();
	for(int i=0;i<l;i++){
		if(i==l-1&&z[i]=='1') a+=1;
		else{
			for(int j=0;j<i;j++){
				f*=2;
			}
			a+=f;
			f=1;
		}
	}
	return a;
}
int px(string a,string b){
	int l1=a.size();
	int l2=b.size();
	int l=max(l1,l2);
	string z="";
	for(int i=0;i<l;i++){
		if(a[i]='1'&&b[i]=='1') z+="1";
		else z+="0";
	}
	return py(z);
}
int p(int a,int b){
	string a1="";
	string b1="";
	while(a>0){
		if(a%2==0) a1+="0";
		else a1+="1";
		a/=2;
	}
	while(b>0){
		if(b%2==0) b1+="0";
		else b1+="1";
		b/=2;
	}
	string a2="",b2="";
	int l1=a1.size(),l2=b2.size();
	for(int i=l1-1;i>=0;i--){
		a2+=a1[i];
	}
	for(int i=l2-1;i>=0;i--){
		b2+=b1[i];
	}
	return px(a2,b2);
}
int main(){
	fropen("and.in","r",stdin);
	fropen("and.out","w",stdout);
	int maxa=0;
	cin>>a>>b;
	for(int i=0;i<a;i++){
		cin>>k[i];
	}
	int s=0;
	for(int i=0;i<a;i++){
		for(int j=i+1;j<=a;j++){
			if(k[j]==0) break;
			if(p(k[i],k[j])>maxa) maxa=p(k[i],k[j]);
		}
	}
	cout<<maxa;
	return 0;
} 
