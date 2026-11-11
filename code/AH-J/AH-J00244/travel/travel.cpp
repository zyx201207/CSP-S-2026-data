#include<bits/stdc++.h>
using namespace std;
string m,n;
string a,b;
int q,p;
int x,y;
bool flag=0,flag2=0,flag3=0;
int main(){
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    cin>>m>>a>>n>>b;
    if(m==n){
        cout<<1;
    }else{
        cout<<0;
        flag3=1;
    }
    q+=a[1]-'0';
    q+=(a[0]-'0')*10;
    p+=b[1]-'0';
    p+=(b[0]-'0')*10;
    x+=a[2]-'A'+1;
    y+=b[2]-'A'+1;
    if(q==p&&flag3==0){
        cout<<1;
    }else{
        cout<<0;
    }
    if(x<=3&&y<=3){
		flag=1;
	}
	if(x>=4&&y>=4){
		flag=1;
	}
    if(q==p&&flag==1&&flag3==0){
		cout<<1;
		
	}else{
		cout<<0;
	}
	if(x+1==y||x-1==y){
		flag2=1;
	}if(x==3&&y==4){
		flag2=0;
	}
	if(q==p&&flag==1&&flag2==1&&flag3==0){
		cout<<1;
	}else{
		cout<<0;
	}
}
