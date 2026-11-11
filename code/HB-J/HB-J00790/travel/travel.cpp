#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int ans,num,k,l;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>c1>>c2;
	for(int i=0;i<2;i++){
		if(s1[i]==c1[i]){
            ans++;
			if(c2[i]==s2[i]) num++;
		}
	}
	if(ans==2){
        cout<<1;
        k=1;
	}
    else cout<<0;
    if(num==2){
        cout<<1;
        l=1;
    }
    else cout<<0;
    if(k!=1 || l!=1){
        cout<<0;
        cout<<0;
    }
	int m=s2[2]-'0',n=c2[2]-'0';
	if(m>=17 && m<=19 && k==1 && l==1){
        if(n>=17 && n<=19) cout<<1;
        else cout<<0;
        if(abs(m-n)==1 && n>=17 && n<=19) cout<<1;
        else cout<<0;
	}
	if(m>=20 && m<=22 && k==1 && l==1){
        if(n>=20 && n<=22) cout<<11;
        else{
            cout<<0;
            cout<<0;
        }
	}
	return 0;
}
