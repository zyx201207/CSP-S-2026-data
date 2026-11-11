#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int s,a,q=0,w=0,e=0,r=0;
	char a1,a2,a3,s1,s2,s3;
	cin>>s;
	cin>>s1;
	cin>>s2;
	cin>>s3;
	cin>>a;
	cin>>a1;
	cin>>a2;
	cin>>a3;
	if(s==a){
		q=1;
		if(s1==a1&&s2==a2){
		w=1;
			if((s3=='D'&&a3=='E')||(s3=='E'&&a3=='D')||(s3=='A'&&a3=='B')||(s3=='A'&&a3==('B'||'C'))||(s3=='C'&&a3=='B')){
				e=1;
				r=1;
			}else if((s3=='A'&&a3=='C')||(s3=='C'&&a3=='A')){
				e=1;
			}	
		}
	}
	cout<<q<<w<<e<<r; 
	return 0;
}  
