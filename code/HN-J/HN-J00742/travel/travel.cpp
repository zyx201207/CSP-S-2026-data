#include<bits/stdc++.h>
using namespace std;
string a1,a2;
int s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>a1>>s2>>a2;
	//cout<<s1<<" "<<a1<<" "<<s2<<" "<<a2<<endl;
	if(s1==s2 && s1!=1 && s1!=16){
		cout<<"1";
		int q=(a1[0]-'0')*10+(a1[1]-'0');
		int w=(a2[0]-'0')*10+(a2[1]-'0');
		//cout<<a1[0]<<" "<<a2[0]<<endl;
		if(q==w){
			cout<<"1";
			char e=a1[2],r=a2[2];
			//cout<<e<<" "<<r<<endl;
			/*
			if(e=='D'&& w=='F') cout<<"11";
			else if(e=='F'&& w=='D') cout<<"11";
			else if(e=='A' && w=='B') cout<<"11";
			else if(e=='B' && w=='C')cout<<"11";
			else if(e=='B' && w=='A') cout<<"11";
			else if(e=='C' && w=='B') cout<<"11";
			else cout<<"00";*/
			if(e=='A' || e=='B' || e=='C'){
			//	cout<<w;
				if(r=='A' || r=='B' || r=='C'){
					//cout<<w<<e;
				cout<<"1";
				if(e-r==1 || r-e==1) cout<<"1";
				else cout<<"0";
			    }else{
			    	cout<<"00";
				}
			}else if(e=='D' || e=='F'){
				if(r=='D' || r=='F'){
				cout<<"11";
			   }else{
			   	cout<<"00";
			   }
			}
		}else cout<<"000";
	}else{
		cout<<"0000";
	}
	return 0;
}
