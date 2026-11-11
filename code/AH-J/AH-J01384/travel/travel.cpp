#include<bits/stdc++.h>
using namespace std;
string b,d;
int a,c;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
	cin>>a>>b>>c>>d;
	bool q=1,w=1,e=1,r=0;
	if(a==c){
		q=1;
	}else{
		q=0;
	}
	for(int i=0;i<=3;i++){
		if(b[i]!=d[i]&&b[i]>='0'&&b[i]<='9'&&d[i]>='0'&&d[i]<='9'){
			w=0;
			break;
		}
	}
	if(w==1){
		w=1;
	}else{
		w=0;
	}
	for(int i=0;i<=3;i++){
		if(b[i]==(char)(d[i]-1)||(char)(b[i]-1)==d[i]&&b[i]>='A'&&b[i]<='C'&&d[i]>='A'&&d[i]<='C'||b[i]>='D'&&b[i]<='F'&&d[i]>='D'&&d[i]<='F'){
            e=1;
            break;
		}
	}
	if(e==0){
		e=0;
	}else{
		e=1;
	}
	for(int i=0;i<=3;i++){
		if(b[i]==(char)(d[i]-1)||(char)(b[i]-1)==d[i]&&b[i]>='A'&&b[i]<='C'&&d[i]>='A'&&d[i]<='C'||b[i]>='D'&&b[i]<='F'&&d[i]>='D'&&d[i]<='F'){
            r=1;
            break;
		}
	}
    if(r==1||a+1==c||c+1==a){
        r=1;
    }else{
        r=0;
    }
	cout<<q<<w<<e<<r;
	return 0;
}
