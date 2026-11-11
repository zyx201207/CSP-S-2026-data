#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char c,d;
    int a[5],b[5];
    for(int i=0;i<2;i++){
    	cin>>a[i]>>c>>b[i]>>d;
	}
	for(int i=0;i<2;i++){
		if(b[i]!=b[i+1]){
			cout<<1000;
			return 0;
		}
		else if(a[i]==a[i+=1] || b[i]==b[i+1]){
			cout<<11;
		}
		else {
			cout<<"0000";
			return 0;
		}
	}
	if(c=='B' || d=='A') cout<<11;
	else if(c=='C' || d=='A') cout<<10;
	else if(c=='A' || d=='B') cout<<11;
	else if(c=='A' || d=='C') cout<<10;
	else if(c=='C' || d=='D') cout<<"00";
	else if(c=='D' || d=='C') cout<<"00";
	else if(c=='D' || d=='F') cout<<11;
	else if(c=='F' || d=='D') cout<<11;
	else if(c=='A' || d=='F') cout<<"00";
	else if(c=='F' || d=='A') cout<<"00";
	else if(c=='B' || d=='F') cout<<"00";
	else if(c=='F' || d=='B') cout<<"00";
	else if(c=='C' || d=='F') cout<<"00";
	else if(c=='F' || d=='C') cout<<"00";
	else if(c=='A' || d=='D') cout<<"00";
	else if(c=='D' || d=='A') cout<<"00";
	else if(c=='B' || d=='D') cout<<"00";
	else if(c=='D' || d=='B') cout<<"00";
	else cout<<"00";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
