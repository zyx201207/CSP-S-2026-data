#include<bits/stdc++.h> 
#include<cstdio>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string z1,z2,l1,l2,c1,s1="z1""l1",c2,s2="z2""l2";
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<0<<0<<0<<0;
	}else{
		cout<<1;
		if("s1"!="s2"){
			cout<<1<<1<<0; 
		}else{
			cout<<1;
			if("s1"-"s2"==1&&"s2"-"s1"==1){
				cout<<1<<1;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
