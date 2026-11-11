#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,b=0,c=0,d=0;
	string s,s1="",s2="",p="";
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>s[i];
		b+=a;
		for(int j=1;j<=a;j++){
		p[d]=s[i];
		d++;
		}	
	}
	for(int i=0;i<b;i++){
		if(b%2==0){
			s1[i]=p[b/2+i+1];
			s2[i]=p[b/2-i];
		}else{
			s1[i]=p[(b+1)/2+i];
			s2[i]=p[b/2-i];
		}
		if(b/2-i==0){
			break;
		}
	}
		for(int i=0;i<=(b+1)/2;i++){
			if(s1[i]!=s2[i]){
				c++;
			}
		}
cout<<c;
	return 0;
}
	 
