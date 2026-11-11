#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
    string s,s1,s2,s3,ans;
    cin>>s>>s1>>s2>>s3;
    if(s!=s2){
    	cout<<"0000";
    	return 0;
	}
	string R,X;
	for(int i=0;i<2;i++){
		R+=s1[i];
		X+=s3[i];
	}
	if(R!=X){
		cout<<"1000";
		return 0;
	}
	int r=int(s1[2]),x=int(s3[2]);
	if((r<=67&&x>67)||(r>67&&x<=67)){
		cout<<"1100";
		return 0;
	}else{
		char jia=char(r+1),jian=char(r-1),dui=s3[2];
		if(jia!=dui&&jian!=dui){
			cout<<"1110";
			return 0;
		}
	}
	cout<<"1111";
	//C:67
	return 0;
}

