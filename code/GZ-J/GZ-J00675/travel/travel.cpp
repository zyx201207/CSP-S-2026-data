//GZ-J00675,遵义航天高级中学,郑子彧 
#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int p(string a,string b){
	int x=1;
	for(int i=0;i<=1;i++){
		if(a[i]!=b[i])	x=0;
	}
	return x;
}
int px(string a,string b){
	if(a[2]<='C'&&b[2]<='C') return 1;
	if(a[2]>='D'&&b[2]>='D') return 1;
	if((a[2]>='D'&&b[2]<='C')||(b[2]>='D'&&a[2]<='C')) return 0;

}
int py(string a,string b){
	if(a[2]-b[2]==1&&a[2]!='D'&&b[2]!='C') return 1;
	if(b[2]-a[2]==1&&b[2]!='D'&&a[2]!='C') return 1;
	else return 0;
}
int main(){
	fropen("travel.in","r",stdin);
	fropen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)cout<<"0000";
	else{
		cout<<"1";
		if(p(s1,s2)==0){
			cout<<"000";
			return 0;
		}
		else{
			cout<<"1";
			if(px(s1,s2)==0){
				cout<<"00";
				return 0;
			}
			else{
				cout<<"1";
				if(py(s1,s2)==0){
					cout<<"0";
					return 0;
				}
				else cout<<"1";
			}
		}
	}
	return 0;
} 
