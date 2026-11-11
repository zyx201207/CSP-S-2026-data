#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }
    int sum=0,num=0,cnt=0,k=0;
	for(int i=0;i<=s1.size();i++){
        if(s1[i]>='0' && s1[i]<='9'
           && s2[i]>='0' && s2[i]<='9'){
            if(s1[i]==s2[i]){
                sum+=1;
            }else{
                sum+=0;
            }
        }else{
            char ch1=s1[i],ch2=s2[i];
            if((s1[3]<='C'&& s2[3]<='C') || (s1[3]>='D'&& s2[3]>='D')){
                cnt=1;
            }else if((s1[3]<='C'&& s2[3]>'C') || (s1[3]>='D'&& s2[3]<'D')){
                cnt=0;
            }
            if((ch1=='C' && ch2=='D') || (ch1=='D' && ch2=='C')){
                num=0;
            }else if(ch1==ch2+1 || ch2==ch1+1){
                num=1;
            }else{
                num=0;
            }
        }
	}
	if(sum==2){
        cout<<1;
	}else{
        cout<<0;
	}
    if(cnt==0){
        cout<<0;
    }else{
        cout<<1;
    }
	if(num==0){
        cout<<0;
	}else{
        cout<<1;
	}
	return 0;
}
