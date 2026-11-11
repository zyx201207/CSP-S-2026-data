#include<bits/stdc++.h>
using namespace std;
int a,b[10000000],n1=0,m1=0,m=0,n=0,k=0;
char c[10000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i=0;i<a;i++){
		 cin>>b[i]>>c[i];
		 if(a%2==0){
			if(i>a/2) m+=b[i];
			else n+=b[i];
		}
		 else{
			 if(i>a/2+1) m1+=b[i];
			 else n1+=b[i];
			 }
	}
	bool f=0;
	for(int i=0;i<a;i++){
		if(c[i]==c[i+1]) f=1;
		else{
			f=0;
			break;
		}
	}
	if(f){
		cout<<0;
		return 0;
	}
	if(a%2==0){
		if(m<n)
			for(int i=0;i<a/2;i++){
				if(c[i]!=c[a-i])k+=b[i];
				else if(c[i]==c[a-i] && b[i]!=b[a-i]) k+=max(b[i],b[a-i])-min(b[i],b[a-i]);
			}
		else{
			int j=1;
			for(int i=a/2;i>=0;i--){
				if(c[i]!=c[i+j])k+=b[i];
				else if(c[i]==c[a-i] && b[i]!=b[a-i]) k+=max(b[i],b[a-i])-min(b[i],b[a-i]);
				j+=2;
			}
		}
		cout<<k;
		return 0;
	}
	else if(a%2!=0){
		if(m<n)
			for(int i=0;i<a/2;i++){
				if(c[i]!=c[a-i])k+=b[i];
				else if(c[i]==c[a-i] && b[i]!=b[a-i]) k+=max(b[i],b[a-i])-min(b[i],b[a-i]);
			}
		else{
			for(int i=a/2;i>=0;i--){
				if(c[i]!=c[a-i])k+=b[i];
				else if(c[i]==c[a-i] && b[i]!=b[a-i]) k+=max(b[i],b[a-i])-min(b[i],b[a-i]);
			}
		}
		cout<<k;
		return 0;
	}
	return 0;
}

