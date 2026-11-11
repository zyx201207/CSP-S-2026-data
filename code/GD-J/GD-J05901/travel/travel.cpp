#include <bits/stdc++.h> 
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	string s,r1,r2,x1,x2;
	string t="",t2r="",t2x=""; 
	cin>>r1>>r2>>x1>>x2;
	if(r1==x1){
		cout<<1;
		t2r=r2[0]+r2[1];
		t2x=x2[0]+x2[1];
		if(t2r==t2x){
			cout<<1;
			if((r2[2]=='D'&&x2[2]=='E')||(r2[2]=='E'&&x2[2]=='D')||((r2[2]!='D'&&x2[2]!='E')&&(r2[2]!='E'&&x2[2]!='D'))){
				cout<<1;
				if(r2[2]-1==x2[2]||r2[2]+1==x2[2]){
				    cout<<1;
			    }
			    else{
				    cout<<0;
			    }
			}
			else{
				cout<<0<<0;
			}
		}
		else{
			cout<<0<<0<<0;
		}
	}
	else{
		cout<<0<<0<<0<<0;
	}
}
