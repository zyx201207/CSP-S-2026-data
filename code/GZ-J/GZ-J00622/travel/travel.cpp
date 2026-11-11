//GZ-J00622	遵义市第四初级中学	肖政言 
#include <bits/stdc++.h>
using namespace std;

bool ans[4],qqq,q;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	char a=s1[2],b=s2[2];
	if(a=='A'){
		if(b=='B'){
			qqq=1;
			q=1;
		}
		if(b=='C'){
			qqq=1;
		}
	}
	if(a=='B'){
		if(b=='A'||b=='C') {
			qqq=1;
			q=1;
		}
		
	}
	if(a=='C'){
		if(b=='B'){
			qqq=1;
			q=1;
		}
		if(b=='A'){
			qqq=1;
		}
	}
	if(a=='D'&&b=='F'){
		qqq=1;
		q=1;
	}
	if(a=='F'&&b=='D'){
		qqq=1;
		q=1;
	}
	
	if(c1[0]==c2[0]&&c1[1]==c2[1]) ans[0]=1;
	if(ans[0]==1&&s1[0]==s2[0]&&s1[1]==s2[1]) ans[1]=1;
	if(ans[1]==1&&qqq==1) ans[2]=1;
	if(ans[1]==1&&q==1) ans[3]=1;
	
	for(int i=0;i<4;i++){
		cout<<ans[i];
	}
	fclose(stdin);
	fclose(stdout);
}

