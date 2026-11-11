#include<bits/stdc++.h>
using namespace std;
int a[200005];
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
int n;
int ans=0;
string s="";
cin>>n;
for(int i=1;i<=n;i++){
	cin>>a[i]>>b[i];
for(int j=1;j<=a[i];j++){
	s=s+b[i];
}
	ans=ans+a[i];
}
bool bb=1;
for(int i=0;i<=ans-1;i++){
	for(int j=ans-1;j>=0;j--){
	if(s[i]==s[j]){
		bb=1;
		
	}else{
	bb=0;
		break;
	}	
	}
}

if(bb==0){
	string ss="",sss="";
	int sum=0;
if(ans%2==0){
	for(int i=0;i<ans/2;i++){
	ss=ss+s[i];
	}
	for(int j=ans-1;j>=ans/2;j--){
		sss=sss+s[j];	
		}
		for(int i=0;i<ans/2;i++){
			if(ss[i]!=sss[i]){
				sum++;
			}	
		}
	cout<<sum;
	
}
else{
	for(int i=0;i<(ans-1)/2;i++){
		ss=ss+s[i];
	}
	for(int j=ans-1;j>=(ans-1)/2+1;j--){
		sss=sss+s[j];	
		}
	
		for(int i=0;i<(ans-1)/2;i++){
			if(ss[i]!=sss[i]){
			
				sum++;
			}	
		}
	cout<<sum;
	
}	
}
else{
cout<<"0";	
}

	return 0;
}
