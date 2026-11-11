//毕节七星关东辰实验学校 刘杰 GZ-J00098
#include<bits/stdc++.h>
using namespace std;

bool isaside(string a,string b){
	char p=a[2];
	if(p>='A'&&p<='C'){
		return b[2]>='A'&&b[2]<='C';
	}
	else{
		return b[2]>='D'&&b[2]<='F';
	}
} 

int to_num(string h){
	int ans=0;
	for(int i=0;i<h.size();i++){
		int j=h[i];
		ans=ans*10+j-'0';
	}
	return ans;
}

bool clse(string a,string b){
	int aa=to_num(a.substr(0,2));
	int bb=to_num(b.substr(0,2));
	if((abs(aa-bb)==0&&(abs(a[2]-b[2])==1))||(abs(aa-bb)==1&&(abs(a[2]-b[2])==0)))    return 1;
	return 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c;string b,d;
	cin>>a>>b>>c>>d;
	if(b[2]=='F')    b[2]='E';
	if(d[2]=='F')    d[2]='E';
	if(a==c)    cout<<1;
	else{
		cout<<"0000"<<endl;return 0;
	}
	if(b.substr(0,2)==d.substr(0,2))    cout<<1;
	else{
		cout<<"000";return 0;
	}
	if(isaside(b,d)){
		cout<<1;
	}
	else{
		cout<<"00"<<endl;return 0;
	}
	if(clse(b,d))    cout<<1;
	else    cout<<0;
} 
