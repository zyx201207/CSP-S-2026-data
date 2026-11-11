//GZ-J00318 贵阳中天中学 吴竣驰 
#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2,w1,w2,p1,p2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	w1=s1[0]+s1[1];
	w2=s2[0]+s2[1];
	if(w1==w2){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	p1=s1[2];
	p2=s2[2];
	if(p1=="A"||p1=="B"||p1=="C"){
		if(p2=="A"||p2=="B"||p2=="C"){
			cout<<1;
			if(p1=="B"||p2=="B"){
				cout<<1;
				return 0;
			}else{
				cout<<0<<0;
				return 0;
			}
		}else{
			cout<<0<<0;
			return 0;
		}
	}else{
		if(p2=="D"||p2=="F"){
			cout<<11;
			return 0;
		}else{
			cout<<00;
			return 0;
		}
	} 
	return 0;
}
