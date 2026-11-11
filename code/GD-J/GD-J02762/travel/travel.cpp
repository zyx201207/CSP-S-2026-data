#include<bits/stdc++.h> 
using namespace std;
string a,b,c,d;
int main(){
	//*
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//*/
	int sum=0;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<1;
			int x=int(b[2]),y=int(d[2]);
			//cout<<x<<" "<<y<<endl;
			if((x>67&&y>67)||(x<=67&&y<=67)){
				cout<<1;
				if((max(x,y)-min(x,y)==1))cout<<1;
				else cout<<"0";
			}
			else cout<<"00";
		}
		
		else cout<<"000";
	}
	else cout<<"0000";
	//*
	fclose(stdin);
	fclose(stdout);
	//*/
	return 0;
}
