//GZ-J00356 ÕÅî£ê» ±Ï½Ú¶«³½ 
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string s1,s2,r1,r2;
	cin>>s1>>s2>>r1>>r2;
	int ans=0;
	int bz=0;
	for(int i=0;i<2;i++){
		if(s1[i]==r1[i]){
			ans++;
		}
	}
	if(ans==2){
		cout<<"1";
		ans-=2;
		bz+=1;
	} else {
		cout<<"0";
		ans-=2;
	}
	for(int i=0;i<2;i++){
		if(s2[i]==r2[i]){
			ans++;
		}
	}
	if(ans==2 && bz==1){
		cout<<"1";
		bz+=1;
	} else {
		cout<<"0";
		
	}
	
	int o=max(s2[2],r2[2]);
	int p=min(s2[2],r2[2]);
	if(bz==2){
	if(o-p==1 || o-p==2){
		if(s2[2]=='C' && r2[2]=='D'){
			cout<<"0";
		} else {
			if(s2[2]=='D' && r2[2]=='C'){
				cout<<"0";
			} else {
				if(s2[2]=='B' && r2[2]=='D'){
				cout<<"0";
			    } else {
				  if(s2[2]=='D' && r2[2]=='B'){
			 	   cout<<"0";
			       } else {
				     if(s2[2]=='F' && r2[2]=='C'){
			           cout<<"0";
			           } else {
				       if(s2[2]=='C' && r2[2]=='F'){
				            cout<<"0";
		                   } else {
				             cout<<"1";
			               }
			           }
			       }
			    }
			}
		}
	}	
	} else {
		cout<<"0";
	}
	
	
	int g=max(s2[2],r2[2]);
	int l=min(s2[2],r2[2]);
	if(bz==2){
		if(g-l==1){
		if(s2[2]=='C' && r2[2]=='D'){
			cout<<"0";
		} else {
			if(s2[2]=='D' && r2[2]=='C'){
				cout<<"0";
			} else {
				cout<<"1";
			}
		}
	}
	} else {
		cout<<"0";
	}
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
