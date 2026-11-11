#include<bits/stdc++.h>
using namespace std;
char a[3]={'A','B','c'},b[2]={'D','F'};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1,s1,sa,c2,s2,sb;
	cin>>c1>>s1>>sa>>c2>>s2>>sb;
	if(c1==c2){
		if(s1==s2){
			for(int i=1;i<5;i++){					
			if(sa==a[i]&&sb==a[i+1]||sb==a[i-1]){
				break;
				cout<<"1111";
				}
				else if(sa==b[i]&&sb==b[i+1]||sb==b[i-1]){
					break;
					cout<<"1111";
				} 
				else if(sa==a[i]&&sb==a[i+2]||sb==a[i-2]){
					break;
					cout<<"1110";
				}
				else{
					break;
					cout<<"1100";
				}
			}
		}
		else cout<<"1000";
	}
	else{
		cout<<"0000";
	}
	return 0;
}
