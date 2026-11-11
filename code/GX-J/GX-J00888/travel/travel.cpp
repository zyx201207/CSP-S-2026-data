#include <bits/stdc++.h>
#include <string>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a=-1;
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<c1.length();i++){
            int aa=0;
		if(c1[i]==c2[i]){
			aa=1;
            a=aa;
		}
	}
	if(a==1){
        cout<<1;
	}else{
        cout<<0;
	}
	int b=-1;
    int l1=s1.length(),l2=s2.length();
	for(int i=0;i<l1-1;i++){
        if(s1[i]==s2[i] && s1[i+1]==s2[i+1]){
            b=1;
        }
	}
	if(a!=1){
        cout<<0;
	}
	else if(b==1){
        cout<<1;
	}else{
        cout<<0;
	}
    int c=-1;
    if(s1[l1-1]=='A' || s1[l1-1]=='B' || s1[l1-1]=='C'){
        if(s2[l2-1]=='A' || s2[l2-1]=='B' || s2[l2-1]=='C'){
            c=1;
            return 0;
        }
    }
    else if(s1[l1-1]=='F' || s1[l1-1]=='D'){
        if(s2[l2-1]=='F' || s2[l2-1]=='D'){
            c=1;
            return 0;
        }
    }
    if(b!=1){
        cout<<0;
    }
    else if(c==1){
        cout<<1;
    }else{
        cout<<0;
    }
    int d=-1;
    string o="ABCDF";
    for(int i=1;i<o.length();i++){
        if(s1[l1-1]==o[i] && s2[l2-1]==o[i+1]){
            d=1;
        }
        else if(s1[l1-1]==o[i] && s2[l2-1]==o[i-1]){
            d=1;
        }
    }
    if(c!=1){
        cout<<0;
    }
    else if(d==1){
        cout<<1;
    }else{
        cout<<0;
    }
    if(a!=1){
        cout<<0000;
        return 0;
    }
    if(b!=1){
        cout<<1000;
        return 0;
    }
    if(c!=1){
        cout<<1100;
        return 0;
    }
    if(d!=1){
        cout<<1110;
        return 0;
    }

    return 0;
}



