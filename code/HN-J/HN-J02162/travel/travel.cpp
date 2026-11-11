#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string cr,sr,cx,sx;
	cin>>cr>>sr>>cx>>sx;
	if (cr!=cx){
		cout<<0<<0<<0<<0;
	}
	else{
		cout<<1;
		if (sr[0]!=sx[0]||sr[1]!=sx[1]){
			cout<<0<<0<<0;
		}
		else{
			cout<<1;
			if ((sr[2]>'C'&&sx[2]>'C')||(sr[2]<'D'&&sx[2]<'D')){
				cout<<1;
				if(abs(sr[2]-sx[2])==1||sr[2]=='D'&&sx[2]=='F'||sr[2]=='F'&&sx[2]=='D'){
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
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
