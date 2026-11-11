#include<bits/stdc++.h>
using namespace std;
map<int,int> a;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	a[(int)'A']=1,a[(int)'B']=2,a[(int)'C']=3,a[(int)'D']=4;a[(int)'F']=5;
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000"<<endl;
	}
	else{
		int m,n;
		m=(s1[0]-'0')*10+(s1[1]-'0');
		n=(s2[0]-'0')*10+(s2[1]-'0');
		if(m==n){
			if((a[s1[2]]<=3&&a[s2[2]]<=3)||(a[s1[2]]>3&&a[s2[2]]>3)){
				if(abs(a[s1[2]]-a[s2[2]])==1) cout<<"1111"<<endl;
				else cout<<"1110";
			}
			else cout<<"1100"<<endl;
		}
		else cout<<"1000"<<endl;
	}
	return 0;
}
