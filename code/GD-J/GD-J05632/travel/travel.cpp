#include<bits/stdc++.h> 
using namespace std;
int ans[5];
char ans1[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	
	cin>>a>>b>>c>>d;
	int t1,t2,t3,t4;
	
	if(a==c){
		ans[0]=1;
		if(b[0]==d[0]&&b[1]==d[1]){
			
			ans[1]=1;
			if('A'<=b[2]&&b[2]<='C'&&'A'<=d[2]&&d[2]<='C'){
				ans[2]=1;
				if(b[2]+1==d[2]||b[2]-1==d[2]){
			    ans[3]=1;
		    }
			}
			else if('D'<=b[2]&&b[2]<='F'&&'D'<=d[2]&&d[2]<='F'){
				ans[2]=1;
				if(b[2]+1==d[2]||b[2]-1==d[2]){
			    ans[3]=1;
		    }
			}
			
		}
		
	}
	for(int i=0;i<4;i++){
		if(ans[i]==0) ans1[i]=48;
		else ans1[i]=49;
	}
	for(int i=0;i<4;i++){
		cout<<ans1[i];
	}
	
	
	return 0;
}
