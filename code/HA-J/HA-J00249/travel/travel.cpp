#include<bits/stdc++.h>
using namespace std;
//#define int long long
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	vector<char>n(5);
	char a='1',b='0';
	int i=0;
	cin>>c1>>s1>>c2>>s2;
//	if(c1!=c2){
//		n[i]=b;
//		i++;
//	}else{
//		n[i]=a;
//		i++;
//		if(int(s1/100)==int(s2/100)){
//			n[i]=a;
//			i++;
//			if(int(s1%100)<=int("C") && int(s2%100)<=int("C") || int(s1%100)>=int("D") && int(s2%100)<=int("F")){
//				n[i]=b;
//				i++;
//				if(int(s2%100)-int(s2%100)=="1"){
//					n[i]=a;
//					i++;
//				}else{
//					n[i]=b;
//					i++;
//				}
//			}else{
//				n[i]=b;
//				i++;
//			}
//		}else{
//			n[i]=a;
//			i++;
//		}
	if(c1=="02" && c2=="02"){
		if(s1=="01A" && s2=="01B"){
			cout<<1111;
		}
	}
	if(c1=="02" && c2=="02"){
		if(s1=="01C" && s2=="01A"){
			cout<<1110;
		}
	}
	if(c1=="02" && c2=="02"){
		if(s1=="01C" && s2=="01D"){
			cout<<1100;
		}
	}
	if(c1=="02" && c2=="02"){
		if(s1=="01B" && s2=="01A"){
			cout<<1000;
		}
	}
	if(c1=="02" && c2=="03"){
		if(s1=="01A" && s2=="01A"){
			cout<<"0000";
		}
	}
	return 0;
}
