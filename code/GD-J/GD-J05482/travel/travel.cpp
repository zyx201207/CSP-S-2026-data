#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("travel.in");
	ofstream fout("travel.out");
	string ans="",cr,sr,cx,sx;
	fin>>cr>>sr>>cx>>sx;
	//cin>>cr>>sr>>cx>>sx;//
	char k='1';
	if(cr==cx){
		ans=ans+'1';
		if(sr[0]==sx[0]&&sr[1]==sx[1]){
			ans=ans+'1';
			if(sr[2]=='A'||sr[2]=='B'||sr[2]=='C'){
				if(sx[2]=='A'||sx[2]=='B'||sx[2]=='C'){
					ans=ans+'1';
					if(sr[2]-1==sx[2]||sr[2]+1==sx[2]){
						ans=ans+'1';
					}
					else{
						ans=ans+'0';
					}
				}
				else{
					ans=ans+'0'+'0';
				}
			}
			else{
				if(sx[2]=='D'||sx[2]=='F'){
					ans=ans+'1'+'1';
				}
				else{
					ans=ans+'0'+'0';
				}
			}
		}
		else{
			ans=ans+'0'+'0'+'0';
		}
	}
	else{
		ans=ans+'0'+'0'+'0'+'0';
	}
	fout<<ans;
	//cout<<ans;//
	fin.close();
	fout.close();
} 
