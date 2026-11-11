#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
int n,m;
struct node{
    string a;
    int g;
}s[200005];
bool cmp(node x,node y){
    if(x.g!=y.g) return x.g>y.g;
    return x.a>y.a;
}
string add(string x,string y){
	string ans="";
	int op=0;
	for(int i=0;i<max(x.size(),y.size());i++){
		int X,Y;
		if(x.size()-1-i>=0){
			X=x[x.size()-1-i]-'0';
		}
		if(y.size()-1-i>=0){
			Y=y[y.size()-1-i]-'0';
		}
		int S=X+Y+op;
		op=S/10;
		ans=(char)(S%10+'0')+ans;
	}
	if(op==1) ans="1"+ans;
	return ans;
}
string CH(string x){
	string ans="";
	int op=0;
	for(int i=x.size()-1;i>=0;i--){
		int S=(x[i]-'0')*2+op;
		op=S/10;
		ans=(char)(S%10+'0')+ans;
	}
	return ans;
}
string change_and(string x,string y){
    string ans_er="";
    while(x!="0"||y!="0"){
        int Sx=(int)(x[x.size()-1]-'0');
        int OPx=Sx%2;
        if(Sx%2==1){
            x[x.size()-1]=(char)(x[x.size()-1]-1);
        }
        string ansl="";
        int opx=0;
        for(int j=0;j<x.size();j++){
            int Si=x[j]-'0';
            Si+=opx*10;
            opx=Si%2;
            ansl+=(Si/2+'0');
        }
        while(ansl[0]=='0'&&ansl.size()>1){
            ansl.erase(0,1);
        }
        x=ansl;

        int Sy=(int)(y[y.size()-1]-'0');
        int OPy=Sy%2;
        if(Sy%2==1){
            y[y.size()-1]=(char)(y[y.size()-1]-1);
        }
        string ansr="";
        int opy=0;
        for(int j=0;j<y.size();j++){
            int Si=y[j]-'0';
            Si+=opy*10;
            opy=Si%2;
            ansr+=(Si/2+'0');
        }
        while(ansr[0]=='0'&&ansr.size()>1){
            ansr.erase(0,1);
        }
        y=ansr;

        if(OPx==1&&OPy==1){
            ans_er+="1";
        }else{
            ans_er+="0";
        }
    }
    string ans="0";
    string tot="1";
    for(int i=0;i<ans_er.size();i++){
		if(ans_er[i]=='1'){
			ans=add(ans,tot);
		}
		tot=CH(tot);
	}
    return ans;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("ans.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i].a;
        int slen=s[i].a.size();
        int ans=0;
        string si=s[i].a;
        while(si!="0"){
            int S=(int)(si[slen-1]-'0');
            if(S%2==1){
                ans++;
            }

            string ansl="";
            int op=0;
            for(int j=0;j<si.size();j++){
                int Si=si[j]-'0';
                Si+=op*10;
                op=Si%2;
                ansl+=(Si/2+'0');
            }
            while(ansl[0]=='0'&&ansl.size()>1){
                ansl.erase(0,1);
            }
            si=ansl;
        }
        s[i].g=ans;
    }
    sort(s+1,s+n+1,cmp);
    string ans=s[1].a;
    for(int i=2;i<=m;i++){
        ans=change_and(ans,s[i].a);
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
