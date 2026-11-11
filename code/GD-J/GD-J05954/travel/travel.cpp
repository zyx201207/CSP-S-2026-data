#include<bits/stdc++.h> 
using namespace std;
bool o(string x,string y){
	if(x==y){
		return 1;
	}
	return 0;
}
bool u(string x,string y){
	if(x[0]==y[0]){
		if(x[1]==y[1]){
			return 1;
		}
	}
	return 0;
}
bool y(string x,string y){
	if(x[2]<'D'&&y[2]<'D'){
		return 1;
	}if(x[2]>='D'&&y[2]>='D'){
		return 1;
	}
	return 0;
}
bool p(string x,string y){
	if(x[2]-'0'+1==y[2]-'0'||x[2]-'0'-1==y[2]-'0'){
		return 1;
	}
	return 0;
}

int main(){
	freopen("travel.in.txt","r",stdin);
	freopen("travel.out.txt","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(o(c1,c2)){
		cout<<1;
		if(u(s1,s2)){
			cout<<1;
			if(y(s1,s2)){
			    cout<<1;
			    if(p(s1,s2)){
			        cout<<1;
			        return 0;
		        }cout<<"0";
		        return 0;
		    }cout<<"00";
		    return 0;
		}cout<<"000";
		return 0;
	}
	cout<<"0000";
	return 0;
	
}
