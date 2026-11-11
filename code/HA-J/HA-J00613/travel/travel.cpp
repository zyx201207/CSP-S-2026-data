#include<bits/stdc++.h>
using namespace std;
long long int c1,c2,l1,l2;
char s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>l1>>s1>>c2>>l2>>s2;
//	cout<<c1<<" "<<c2<<" "<<l1<<" "<<s1<<' '<<l2<<" "<<s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}else{
		if(l1==l2){
			if(int(s1)>=65 && int(s1)<=67 && int(s2)>=65 && int(s2)<=67  || int(s1)==68 && int(s2)==69 || int(s2)==68 && int(s1)==69){
				if(int(s1)-int(s2)==1 || int(s1)-int(s2)==-1){
					cout<<"1111";
					return 0;
				}else{
					cout<<"1110";
					return 0;
				}
			}else{
				cout<<"1100";
				return 0;
			}
		}else{
			cout<<"1000";
			return 0;
		}
	}
	


	return 0;
}

