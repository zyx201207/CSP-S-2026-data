#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,n1,n2;
	string s1,s2;
	char ch1,ch2;
	cin>>c1>>s1>>c2>>s2;
	n1=10*(s1[0]-'0')+s1[1]-'0';
	n2=10*(s2[0]-'0')+s2[1]-'0';
	ch1=s1[2];
	ch2=s2[2];
	if(c1==c2){
		cout<<1;
		if(n1==n2){
			cout<<1;
			if((ch1>='A'&&ch1<='C')&&(ch2>='A'&&ch2<='C')||
			   (ch1>='D'&&ch1<='E')&&(ch2>='D'&&ch2<='E')){
			   	cout<<1;
			   	if(abs(ch1-ch2)==1){
			   		cout<<1;
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000"; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
