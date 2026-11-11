#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    int sum=0;
	string x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	if(x1==x2){
        sum++;
		int u=0;
		for(int i=0;i<y1.size()-1;i++){
			if(y1[i]!=y2[i]) u=1;
		}
		if(u==0){
			sum++;
			int t1=0;
			int t2=0;
			t1=y1[2];
			t2=y2[2];
			if((t1<=67&&t2<=67)||(t1>=68&&t2>=68)){
				sum++;
				if(t1<=67){
					if(t1==t2-1||t1==t2+1) sum++;
				}
				else if(t1>=68){
					if(t1==t2-2||t1==t2+2) sum++;
				}
			}
		}
	}
	for(int i=1;i<=4;i++){
		if(i<=sum) cout<<"1";
		else cout<<"0";
	}
	return 0;
}
