#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
char p,q;
long long a,b;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin>>a>>s1>>b>>s2;
	if(a==b){
		cout<<1;
		s3+=s1[0];s3+=s1[1];
		s4+=s2[0];s4+=s2[1];
		if(s3==s4){
			cout<<1;
			p=s1[2],q=s2[2];
			bool f=0;
			if(p=='A'||p=='B'||p=='C'){
				if(q=='A'||q=='B'||q=='C') f=1;
				else f=0;
			}else if(p=='D'||p=='F'){
				if(q=='D'||q=='F') f=1;
				else f=0;
			}
			if(f==1){
				long long ff=0;
				cout<<1;
				if(p=='A'){
					if(q=='B') ff=1;
				}else if(p=='B'){
					if(q=='A'||q=='C') ff=1;
				}else if(p=='C'){
					if(q=='B') ff=1;
				}else if(p=='D'){
					if(q=='F') ff=1;
				}else if(p=='F'){
					if(q=='D') ff=1;
				}
				if(ff==1) cout<<1;
				else cout<<0;	
			}else{
				cout<<"00";
			}
		}else cout<<"000";	
	}else cout<<"0000";
	
	return 0;
}
