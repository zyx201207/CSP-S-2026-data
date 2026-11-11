#include <bits/stdc++.h>
using namespace std;
int where(char n,char m){
    if((n=='A'||n=='B'||n=='C')&&(m=='A'||m=='B'||m=='C'))return 1;
    if((n=='D'||n=='F')&&(m=='F'||m=='D'))return 1;
    else return 0;
}
int near(char n,char m){
   if(n=='A'){
       if(m=='B') return 1;
       else return 0;
   }
   if(n=='B'){
       if(m=='A'||m=='C') return 1;
       else return 0;
   }
   if(n=='C'){
       if(m=='B') return 1;
       else return 0;
   }
   if(n=='D'){
       if(m=='F') return 1;
       else return 0;
   }
   if(n=='F'){
       if(m=='D') return 1;
       else return 0;
   }
}

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int cnt1=1,cnt2=1,cnt3=1;
    cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2) cout<<1;
	else{
	    cout << 0;
	    cnt1=0;
	    cnt2=0;
	    cnt3=0;
    }
	for(int i=0;i<2;i++){
        if(s1[i]!=s2[i]){
            cnt1=0;
            cnt2=0;
            cnt3=0;
		}
	}
	if(s1[2]==s2[2]){
	    cnt1=0;
	    cnt2=0;
	    cnt3=0;
    }
    if(where(s1[2],s2[2])==0){
        cnt2=0;
        cnt3=0;
    } 
    if(near(s1[2],s2[2])==0) cnt3=0;
    cout << cnt1 << cnt2 << cnt3;
	return 0;
}
