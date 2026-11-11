#include<bits/stdc++.h>
using namespace std;

int n,b,cnt,num,ans;
long long tot;
struct str{
	int a,st,en;
	char c;
}s[200005];


int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i].a>>s[i].c;
		s[i].st=tot;
		s[i].en=tot+s[i].a-1;
		tot+=s[i].a;
	}
	if(tot%2==1){
		b=floor(tot*1.0/2);
		for(int i=0;i<n;i++){
			if(s[i].st<=b&&b<=s[i].en){
				cnt=i;
				break;
			}
		}
		int a1=0,a2=0,cnt1=cnt,cnt2=cnt,i=0;
	    while(1){
	    	i++;
	    	if(b-i<s[cnt1].st){
	    		cnt1--;
			}
			if(b+i>s[cnt2].en){
				cnt2++;
			}
			if(s[cnt1].c!=s[cnt2].c) ans++;
			if(b-i<0) break;
		}
		cout<<ans;
	}	
	
	else{
		b=tot/2;
		int a1=0,a2=0,cnt1=cnt,cnt2=cnt,i=0;
		while(1){
	    	i++;
	    	if(b-i<s[cnt1].st){
	    		cnt1--;
			}
			if(b+i>s[cnt2].en){
				cnt2++;
			}
			if(s[cnt1].c!=s[cnt2].c) ans++;
			if(b-i<0) break;
		}
		cout<<ans;	
	}
	return 0;
}
