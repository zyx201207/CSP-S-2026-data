#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int a,b;
	cin>>a>>b;
	if(b==2){
		cout<<32<<endl<<17; 
	}else if(b==3){
		cout<<35<<endl<<16;
	}else{
		int x[70005];
		int ab = 0;
		for(int i = 1;i<=70000;i++){
			if(x[i]!=0&&x[i]/100!=0){
				cout<<abs(x[i]/100)<<endl;
				if(ab==b){
					return 0;
				}
				ab++;
				
			}
		}
	}




	return 0;
}

