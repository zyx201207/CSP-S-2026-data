#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
char bc,bd;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    int ch1=0,ch2=0;
    int zw1=0,zw2=0;
    int len1=c1.size();
    int len2=c2.size();
    int flag1=0;
    int flag2=0;
    for(int i=0;i<=len1;i++){
        if(c1[i]-'0'>=1&&c1[i]-'0'<=9){
            ch1=ch1*10+(c1[i]-'0');
            flag1=1;
        }
        else if(flag1==1&&c1[i]-'0'==0)
            ch1*=10;
    }
    for(int i=0;i<=len2;i++){
        if(c2[i]-'0'>=1&&c2[i]-'0'<=9){
            ch2=ch2*10+c2[i]-'0';
            flag2=1;
        }
        else if(flag2!=0&&c2[i]-'0'==0)
            ch2*=10;
	}
    len1=s1.size();
    len2=s2.size();
    flag1=0;
    flag2=0;
    for(int i=0;i<=len1;i++){
        if(s1[i]>='A'&&s1[i]<='F')
            bc=s1[i];
        if(s1[i]-'0'>=1&&s1[i]-'0'<=9){
            zw1=zw1*10+s1[i]-'0';
            flag1=1;
        }
        else if(flag1!=0&&s1[i]-'0'==0)
            zw1*=10;
    }
    for(int i=0;i<=len2;i++){
        if(s2[i]>='A'&&s2[i]<='F')
            bd=s2[i];
        if(c2[i]-'0'>=1&&s2[i]-'0'<=9){
            zw2=zw2*10+s2[i]-'0';
            flag2=1;
        }
        else if(flag2!=0&&s1[i]-'0'==0)
            zw2*=10;
    }
	if(ch1==ch2)
        cout<<1;
    else{
    	cout<<"0000";
    	return 0;
	}
    if(zw1==zw2){
        cout<<1;
        if((bc<='C'&&bc>='A')&&(bd<='C'&&bd>='A')){
            cout<<1;
            if(bc+1==bd||bc-1==bd)
                cout<<1;
            else
                cout<<0;
        }
		else if((bc<='F'&&bc>='D')&&(bd<='F'&&bd>='D')){
			cout<<1;
            if(bc+1==bd||bc-1==bd)
                cout<<1;
            else
                cout<<0;
		}
        else
            cout<<"00";
    }
    else
        cout<<"000";
    return 0;
}
