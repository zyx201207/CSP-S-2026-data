#include<bits/stdc++.h>
using namespace std;
int a,n[10],b,m[10];
char c[10];
int S(int x){
	for(int i=0;i<3;i++){
		cin>>c[i];
	}
	n[x]=10*c[0]+c[1];
	m[x]=c[2];
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a;
	S(0);
	cin>>b;
	S(1);
	if(a==b){
		cout<<"1";
		if(n[0]==n[1]){
			cout<<"1";
			if(m[0]<=67&&m[1]<=67){
				cout<<"1";
				if(m[0]-m[1]==1||m[0]-m[1]==-1){
					cout<<"1";
				}
				else cout<<"0";
			}
			else if(m[0]>=68&&m[1]>=68) cout<<"11";
			else cout<<"00";
		}
		else cout<<"000";
	} 
	else cout<<"0000";
	
	

	return 0;
}
