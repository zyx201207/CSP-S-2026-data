#include<bits/stdc++.h>
#define ll long long
using namespace std;
string a,b,c,d,a1,a2;
struct data{char a,b;};
data t[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	t[0]={'B','0'},t[1]={'A','C'},t[2]={'B','0'},t[3]={'F','0'},t[5]={'D','0'};
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<'1';
		a1=b[0]+b[1],a2=d[0]+d[1];
		if(a1==a2){
			cout<<'1';
			if((b[2]-'A'<3&&d[2]-'A'<3)||(b[2]-'A'>=3&&d[2]-'A'>=3)){
				cout<<'1';
				if(t[b[2]-'A'].a==d[2]||t[b[2]-'A'].b==d[2]){
					cout<<'1';
				}else cout<<'0';				
			}else cout<<"00";

		}else{
			cout<<"000";
		}
	}else {
		cout<<"0000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
