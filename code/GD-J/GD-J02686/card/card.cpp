#include<bits/stdc++.h>
using namespace std;
int sp[500004],zm[500004];
int t[300004];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a,s,gs=0,xb=0;
	cin>>a>>s;
	bool jx=false;
	for(int i=0;i<a;i++) cin>>sp[i];
	for(int g=0;g<a;g++){
		for(int i=g;i<a;i++){
			jx=false;
			for(int j=0;j<gs;j++){
				if(zm[j]==sp[i]){
					xb=j;
					jx=true;
					break;
				}
			}
			if(jx){
				for(int j=xb+1;j<gs;j++) zm[j]=0;
				gs=xb+1;
			}
			else{
				zm[gs]=sp[i];
				gs++;
			} 
		}
		for(int i=0;i<gs;i++){
			t[zm[i]]++;
			zm[i]=0;
		} 
	}
	for(int i=1;i<=s;i++){
		cout<<t[i]<<' ';
	}
	return 0;
} 
