#include<bits/stdc++.h>
using namespace std;
const int N=int('Z')+15;
string c1,s1,c2,s2;
int f[N][N],d[N][N];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	f['A']['B']=f['B']['A']=1;
	f['A']['C']=f['C']['A']=1;
	f['B']['C']=f['C']['B']=1;
	f['F']['D']=f['D']['F']=1;
	d['A']['B']=d['B']['A']=1;
	d['B']['C']=d['C']['B']=1;
	d['F']['D']=d['D']['F']=1;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if(f[s1[2]][s2[2]]){
				cout<<1;
				if(d[s1[2]][s2[2]])cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}	
		else cout<<"000";
	}
	else{
		cout<<"0000";
	} 
	
	return 0;
}
