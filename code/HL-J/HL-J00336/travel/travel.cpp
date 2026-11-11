#include <bits/stdc++.h>
using namespace std;
string r1;
string r2;
string x1;
string x2;
int cnt=0,cnt1=0,cnt2=0,cnt3=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r1>>r2>>x1>>x2;
	for(int i=0;i<2;i++){
		if(r1[i]!=x1[i]){
			cnt=1;
		}
	}
	if(cnt==0){
		cout<<1;
		if(r2[0]==x2[0]&&r2[1]==x2[1]){
			cout<<1;
				if(int(r2[2])==int(x2[2])+1||int(r2[2])==int(x2[2])-1){
				cnt1=0;
				if(r2[2]=='C'||x2[2]=='C'){
					if(x2[2]=='D'||r2[2]=='D'){
						cnt2=1;
						cnt1=1;
					}
				}
				else{
					cnt2=0;
				}
			}
			else{
				cnt1=1;
				if(r2[2]=='A'||x2[2]=='A'){
					if(x2[2]=='C'||r2[2]=='C'){
						cnt2=0;
					}
				else cnt2=1;
				}
			}
		if(cnt2==0) cout<<1;
		else cout<<0;
		if(cnt1==0) cout<<1;
		else cout<<0;
		}
		else cout<<0<<0<<0;
		
	}
	else cout<<0<<0<<0<<0;
	
	return 0;
} 
