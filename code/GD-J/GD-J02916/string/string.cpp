#include<bits/stdc++.h>
using namespace std;
long long n,sz,p,cd,gs,da;
char zm,gzm;
string ss;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&gs); 
		cin>>zm;
		if(gzm!=zm&&p==0&&i!=1){
			p=1;
		}	
		cd+=gs;
		gzm=zm;
		
		for(int j=1;j<=gs;j++){
			ss+=zm;
		}
	}
	if(p==0) cout<<"0",exit(0); 
	if(cd%2==0){
		for(int i=0;i<=(cd-1)/2;i++){
			if(ss[i]!=ss[cd-1-i]) da++;
		}
		cout<<da,exit(0);
	}
	else {
		for(int i=0;i<=(cd-1)/2-1;i++){
			if(ss[i]!=ss[cd-1-i]) da++;
		}
		cout<<da,exit(0);
	}
} 
