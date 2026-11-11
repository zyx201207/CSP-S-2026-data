#include<bits/stdc++.h>
using namespace std;
#define ll long long
	ll c,t;
	ll n,d,x[300000],s=0,s1=0,ss=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>d;
		for(int j=0;j<n;j++){
			cin>>x[i];
		}
		for(int j=0;j<n;j++){
			if(j+d<n){
				j+d;
				s++;
			}else if(!(j+d==n)){
				s++;
				break;
			}
			
		}
		for(int j=1;j<d;j++){
			s1++;
			if(j+d<=n){
				s1++;
			} 
			else{
				s1++;
			}
			if(s1<s){
				s++;
			}
		} 
		 if(s!=2){
		 	cout<<s;
		 }else{
		 	ss++;
		 }
		
	} 
		cout<<ss;	
	return 0;
} 
