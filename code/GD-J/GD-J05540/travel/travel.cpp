#include<bits/stdc++.h>
using namespace std;
string w1,c1,c2,w2;
bool b[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cin>>w1;
	cin>>c1;
	cin>>w2;
	cin>>c2;
	if(w1[0]==w2[0]&&w1[1]==w2[1]){
		b[1]=true;
			if(c1[0]==c2[0]&&c1[1]==c2[1]){
				b[2]=true;
				if(c1[2]>='A'&&c1[2]<='C'&&c2[2]>='A'&&c2[2]<='C'){
					b[3]=true;
					if(abs(c1[2]-c2[2])==1)
						b[4]=true;
				}
				else if(c1[2]>='D'&&c1[2]<='F'&&c2[2]>='D'&&c2[2]<='F'){
					b[3]=1;
					b[4]=1;	
				}
			}	
	}
	for(int i=1;i<=4;i++){
		cout<<b[i];
	}
	return 0;
} 
