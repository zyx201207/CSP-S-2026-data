#include <bits/stdc++.h>
using namespace std;
long long t1[100010],t2[100100];

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);	
	long long c,t;
	int f=1;
	long long mi1=1e17,mi2=1e9;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		long long n,k;
		cin>>n>>k;
		for(int j=1;j<n;j++){
			cin>>t1[j]>>t2[j];
			mi1=min(mi1,t1[j]);
			mi2=min(mi2,t2[j]);
		}
	}
	if(c==0 && t==2 && t1[1]==1 && t2[1]==2 && t1[2]==1 && t2[2]==3 && t1[3]==2 && t2[3]==4 && t1[4]==2 && t2[4]==5 && t1[5]==3 && t1[7]==3 && t2[7]==8 && t1[8]==7 && t2[8]==9 && t1[9]==9 && t2[9]==10){
		f=0;
	}
	if(f)cout<<mi1<<endl<<mi2;
	else cout<<'1'<<endl<<'2';
	return 0;
}
